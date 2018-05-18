# ToJump-
基于opencv与stc89c52

基于图像识别与单片机的微信“跳一跳”游戏“物理外挂
一、作品简要介绍（包含用途）
  微信跳一跳是一款超级好玩的休闲小游戏，但想拿高分并不是那么容易。这种情况下我们就设计了这个简单物理外挂。这样一个装置是以51单片机为数据处理中心，图像识别技术作为信号接收源，性能优良的舵机作为最终的执行对象。通过清晰明了的语言指令为整个操作过程实施指令。选用体积小，处理性能强的51单片机作为这个项目的核心部分，使用单片机8位CPU且具有4kb的ROM和128KB的RAM，轻而易举地支撑起了整个操作过程。编程语言的连贯性使整个过程的运行变得更加行云流水，并配以以opencv为中心的图像处理技术，大大减少了程序编写长度。微信跳一跳的简单物理外挂是一款超级好用的刷分神器，只需简简单单的操作步骤，即可实现玩家夺取好友榜第一的愿望 。在使用中，仅需将手机与物理外挂电路板分别与计算机建立通信即可，具有操作方法简单的特点。
二、作品原理、电路图
1.	作品原理：
  1）	图像捕捉：
    运用相关手机管理软件（如360手机管家）或abd进行屏幕实时捕捉。
  2）图像处理
    以vc2015为开发平台，连接opencv计算机视觉库，以c/c++语言为主要编程语言，进行以下作品所需的图像识别算法。
  ①	获取棋子位置：
    事先将棋子图像进行单独截图保存，以模板匹配算法获取游戏中棋子的位置。
  ②	边缘检测：
     首先对图片进行高斯模糊处理，以减少噪声。再用canny算子进行边缘检测。
  ③	获取目标平台几何中心位置
     用Cannay算子处理后的二值图像进行轮廓的寻找，并遍历轮廓，以最外层轮廓在y轴方向上的最小值为中心点的y轴坐标，以最外层轮廓在在x轴方向上的最大值为中心点的x轴坐标。
  ④	计算跳跃距离：
    通过原点坐标与目标坐标进行距离计算。
  ⑤	计算按压时间：
    通过测量两个屏幕大小不同的设备进行游戏是的按压时间与距离，以设备显示跳跃距离与两个设备屏幕大小的比例，计算出实际的跳跃距离。并分别建立“按压时间-跳跃距离”训练集，采用线性回归算法与梯度下降算法对“按压时间-跳跃距离”进行数学建模，得出“按压时间-跳跃距离”数学关系式。以此通过跳跃距离计算出按压时间。
  3）嵌入式系统控制：
    以51单片机为核心控制元件，以sg90舵机对手机进行直接控制。
      （1）	串口通信：
      将嵌入式系统与电脑进行USB连接，在系统中采用ch340芯片，实现USB转TTL；通过串口通信，将按压时间由计算机传送给单片机。
      （2）	sg90舵机：
      使用积分电路和PWM对sg90舵机旋转角度进行控制，以此完成按压
      时间的操作。
三、电路图
注：因暂未掌握protues的使用方法，所以在此以手绘电路图的形式展现。


