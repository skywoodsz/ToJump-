#include<opencv2/opencv.hpp>
#include<iostream>
#include<windows.h>

#include <cstdio>    
#include <string>  
#include <tchar.h>  
using namespace cv;
using namespace std;
//  ԭͼ��      ģ��ƥ��ͼ�� ������ͼ����Ե���ͼ��    �ָ�ͼ 
Mat g_srcImage, g_tempImage, g_dstImage, g_Canny_dstImage, g_ROI_dstImage;
//ģ��ƥ�䷽ʽ��
int g_MatchMethod = 5;
//ģ��ƥ�����ϵ�
Point g_matchLocation;
//Ŀ�������
Point g_dst_nextPoint;
//Ŀ���ԭͼ����
Point g_src_nextPoint;
//����
Point g_c_nextPoint;
Point g_c_matchLocation;
int g_dis=0, g_time = 0;
//��ȡ�ֻ���ͼ
void get_screenshot();
//ģ��ƥ��
Point Matching(int, void*);
//����
static void DrawFilledCircle(Mat img, Point center);
//��Ե���
Mat Cannying(Mat img);
//����Ŀ�����ĵ�
Point GetNextPoint(Mat img);
//�����������
int GetDistance(Point beg, Point end);
//��ѹ
void jump(int&g_distance);
int time(int dis);
void toJump(int time);
int main()
{
	while (1)
		//for(int i=0;i<2;i++)
	{
		//��ȡ�ֻ���ͼ
		get_screenshot();
		//����Ϸԭͼ
		g_srcImage = imread("D:/��ѧ/��Է��/autojump.png", 1);
		//g_srcImage = imread("D:/��ѧ/��Է��/�������/1.png", 1);
		if (!g_srcImage.data)
		{
			printf("error!��ȡg_src����~");
			return -1;
		}

		//��ƥ��ģ��
		g_tempImage = imread("D:/��ѧ/��Է��/tempCopy2.png", 1);
		if (!g_tempImage.data)
		{
			printf("error!��ȡg_temp����~");
			return -1;
		}

		namedWindow("��ԭͼ��", WINDOW_NORMAL);
		//imshow("��ԭͼ��",g_src);
		//imshow("��ƥ��ģ�塿", g_temp);
		//createTrackbar("ƥ�䷽��","��ԭͼ��",&g_MatchMethod,5,on_Matching);

		//����ģ��ƥ�䲢����С������������
		g_matchLocation = Matching(0, 0);
		
		printf("С��λ��Ϊ��(%d,%d)\n", g_matchLocation.x, g_matchLocation.y);
		//��С��������������б��
		DrawFilledCircle(g_srcImage, g_matchLocation);

		//��ʾ���ͼ
		//imshow("��ԭͼ��", g_srcImage);

		//����ͼƬ
		g_ROI_dstImage = g_srcImage(Rect(0, 300, g_srcImage.cols, g_srcImage.rows / 2 - 350));
		/*namedWindow("��ROI��", WINDOW_NORMAL);
		imshow("��ROI��", g_ROI_dstImage);*/

		//��Ե���
		g_Canny_dstImage = Cannying(g_ROI_dstImage);
		/*namedWindow("����Ե��⡿", WINDOW_NORMAL);
		imshow("����Ե��⡿", g_Canny_dstImage);*/
		//��ȡĿ���
		g_dst_nextPoint = GetNextPoint(g_Canny_dstImage);
		g_src_nextPoint = Point(g_dst_nextPoint.x, g_dst_nextPoint.y + 300);
		printf("Ŀ���Ϊ��(%d,%d)", g_src_nextPoint.x, g_src_nextPoint.y);
		DrawFilledCircle(g_Canny_dstImage, g_dst_nextPoint);
		/*namedWindow("��Ŀ����ȡ��", WINDOW_NORMAL);
		imshow("��Ŀ����ȡ��", g_Canny_dstImage);*/
		//���Ŀ���
		DrawFilledCircle(g_srcImage, g_src_nextPoint);
		//imshow("��ԭͼ��", g_srcImage);
		//����������벢���
		g_dis = GetDistance(g_matchLocation, g_src_nextPoint);
		printf("�������Ϊ%d ppi\n", g_dis);
		//printf("(%d,%d)",g_src_nextPoint.x, g_src_nextPoint.y);
		g_time = time(g_dis);
		printf("��Ծʱ��Ϊ%d ppi\n", g_time);
		toJump(g_time);
		//����ESCʱ�˳�
		//jump(g_dis);
		imshow("��ԭͼ��", g_srcImage);
		//while (i--);
		Sleep(1000);
		//����space��ͣ������q���¿�ʼ
		if (waitKey(1) == 32)
			while (waitKey(1) != 113);
		//����ESC�˳�
		if (waitKey(1000) == 27)break;
	}
	while (waitKey(1) != 27);
	return 0;
}
//��ȡ�ֻ���ͼ
void get_screenshot()
{
	system("adb shell screencap -p /sdcard/autojump.png");
	system("adb pull /sdcard/autojump.png D:/��ѧ/��Է��/autojump.png");
}

//���÷�ʽ������ģ��ƥ�䲢����С�����������꣬
Point Matching(int, void*)
{
	int resultImage_rows = g_srcImage.rows + g_tempImage.rows + 1;
	int resultImage_cols = g_srcImage.cols + g_tempImage.cols + 1;
	g_dstImage.create(resultImage_rows, resultImage_cols, CV_32FC1);

	matchTemplate(g_srcImage, g_tempImage, g_dstImage, g_MatchMethod);
	normalize(g_dstImage, g_dstImage, 0, 1, NORM_MINMAX, -1, Mat());

	double minValue, maxValue;
	Point minLocation, maxLocation, matchLocation;
	minMaxLoc(g_dstImage, &minValue, &maxValue, &minLocation, &maxLocation, Mat());

	if (g_MatchMethod == TM_SQDIFF || g_MatchMethod == TM_SQDIFF_NORMED)
	{
		matchLocation = minLocation;
	}
	else
	{
		matchLocation = maxLocation;
	}

	rectangle(g_srcImage, matchLocation,
		Point(matchLocation.x + g_tempImage.cols, matchLocation.y + g_tempImage.rows),
		Scalar(0, 0, 255), 2, 8, 0);
	rectangle(g_dstImage, matchLocation,
		Point(matchLocation.x + g_tempImage.cols, matchLocation.y + g_tempImage.rows),
		Scalar(0, 0, 255), 2, 8, 0);
	return Point(matchLocation.x + g_tempImage.cols / 2, matchLocation.y + g_tempImage.rows);
}
//���С������������
static void DrawFilledCircle(Mat img, Point center)
{
	int thickness = -1;
	int lineType = 8;
	circle(img, center, 10, Scalar(0, 0, 0), thickness, lineType);
}
//Canny��Ե���
Mat Cannying(Mat img)
{
	Mat dst, edge, gray;
	dst.create(img.size(), img.type());
	cvtColor(img, gray, COLOR_BGR2GRAY);
	GaussianBlur(gray, edge, Size(3, 3), 0, 0);
	Canny(edge, edge, 3, 6, 3);
	return edge;
}
Point GetNextPoint(Mat img)
{
	double tim=0;
	tim = tim + 1;
	cout << "tim:" << tim << endl;
	Point point1, point2;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(img, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE, Point());
	vector<vector<Point>>::const_iterator it = contours.begin();

	while (it != contours.end())
	{
		if (it->size() < 20)
			it = contours.erase(it);
		else
			++it;
	}
	int nYMin = img.rows;
	int nXMin = img.cols;
	int nYMax = 0;
	int nXMax = 0;
	int nIdY = 0;

	
	for (int i = 0; i < contours.size(); i++)
	{
		cout << "contours1:" << contours[i].size() << endl;
		for (int j = 0; j < contours[i].size(); j++)
		{
			
			if (contours[i][j].y < nYMin)
				nYMin = contours[i][j].y;
			point1 = contours[i][j];
			nIdY = i;
		}
	}
	int minY = img.cols;
	
	for (int j = 0; j < contours[nIdY].size(); j++)
	{
		cout << "contours2:" << contours[nIdY].size() << endl;
		if (contours[nIdY][j].x >nXMax)
		{
			nXMax = contours[nIdY][j].x;
		}
	}
	for (int j = 0; j < contours[nIdY].size(); j++)
		if (contours[nIdY][j].x == nXMax && contours[nIdY][j].y < minY)
		{
			point2 = contours[nIdY][j];
			minY = contours[nIdY][j].y;     //��¼X������ֵ
		}
	/*vector<vector<Point>>temp1;
	vector<Vec4i>temp2;
	/contours.swap(temp1);
	hierarchy.swap(temp2);*/
	//printf("(%d,%d)",point2.x,point2.y);
	//printf("(%d,%d)", point2.x, point2.y);
	//printf("(%d,%d)", point1.x, point1.y);
	contours.clear();
	hierarchy.clear();
	return Point(point1.x, point2.y);
}
int GetDistance(Point beg, Point end)
{
	int x = end.x - beg.x;
	int y = end.y - beg.y;
	int dis = pow((pow(x, 2) + pow(y, 2)), 0.5);
	return dis;
}
//��ѹ
void jump(int&dis)
{
	char AA[50];
	int time = dis* 1.35;
	printf("��ѹʱ�䣺%d\n", time);
	int rand_x = int(320 + rand() % 80); //���������ʹ��ÿ�ΰ�ѹ�����ڵ㣨320,410��-��370,460��֮��
	int rand_y = int(410 + rand() % 80);
	sprintf(AA, "adb shell input swipe %d %d %d %d %d", rand_x, rand_y, rand_x, rand_y, time);
	//sprintf(AA, "adb shell input swipe %d %d %d %d %d", 320, 410, 320, 410, time);
	cout << AA << endl;
	system(AA);
}
int time(int dis)
{
	int time = dis*1.35;
	return time;
}
void toJump(int time)
{
	int time_b, time_s, time_g;
	time_b = time / 100;
	time_s = time % 100 / 10;
	time_g = time%100%10;
	//���ھ��
	HWND hWnd = (HWND)0x00020454;
	//���;��q
	HWND hbutton = (HWND)0x00020452;

	//���Ͱ�λ
	const char* dat_b;
	string temp_b = to_string(time_b);
	dat_b = temp_b.c_str();
	SendMessage(hWnd, WM_SETTEXT, NULL, (LPARAM)dat_b);
	Sleep(1000);
	SendMessage(hbutton, WM_LBUTTONDOWN, (int)0, NULL);
	SendMessage(hbutton, WM_LBUTTONUP, (int)0, NULL);
	Sleep(1000);
	//����ʮλ
	const char* dat_s;
	string temp_s = to_string(time_s);
	dat_s = temp_s.c_str();
	SendMessage(hWnd, WM_SETTEXT, NULL, (LPARAM)dat_s);
	Sleep(1000);
	SendMessage(hbutton, WM_LBUTTONDOWN, (int)0, NULL);
	SendMessage(hbutton, WM_LBUTTONUP, (int)0, NULL);
	Sleep(1000);
	//���͸�λ
	const char* dat_g;
	string temp_g = to_string(time_g);
	dat_g = temp_g.c_str();
	SendMessage(hWnd, WM_SETTEXT, NULL, (LPARAM)dat_g);
	Sleep(1000);
	SendMessage(hbutton, WM_LBUTTONDOWN, (int)0, NULL);
	SendMessage(hbutton, WM_LBUTTONUP, (int)0, NULL);
	Sleep(2000);
}
