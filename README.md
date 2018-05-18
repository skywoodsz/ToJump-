# ToJump-
基于opencv与stc89c52

<h1 style="margin: 22.66px 0px 22px;"><span style="margin: 0px; font-family: 宋体;"><font size="6">基于图像识别与单片机的微信“跳一跳”游戏“物理外挂</font></span><span lang="EN-US" style="margin: 0px;"></span></h1>

<p align="left" style="margin: 0px; text-align: left; line-height: 150%; text-indent: 0cm;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">一、</span></span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">作品简要介绍（包含用途）<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px; text-align: left; line-height: 150%; text-indent: 28pt;"><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">微信跳一跳是一款超级好玩的休闲小游戏，但想拿高分并不是那么容易。这种情况下我们就设计了这个简单物理外挂。这样一个装置是以<span lang="EN-US" style="margin: 0px;">51</span>单片机为数据处理中心，图像识别技术作为信号接收源，性能优良的舵机作为最终的执行对象。通过清晰明了的语言指令为整个操作过程实施指令。选用体积小，处理性能强的<span lang="EN-US" style="margin: 0px;">51</span>单片机作为这个项目的核心部分，使用单片机<span lang="EN-US" style="margin: 0px;">8</span>位<span lang="EN-US" style="margin: 0px;">CPU</span>且具有<span lang="EN-US" style="margin: 0px;">4kb</span>的<span lang="EN-US" style="margin: 0px;">ROM</span>和<span lang="EN-US" style="margin: 0px;">128KB</span>的<span lang="EN-US" style="margin: 0px;">RAM</span>，轻而易举地支撑起了整个操作过程。编程语言的连贯性使整个过程的运行变得更加行云流水，并配以以<span lang="EN-US" style="margin: 0px;">opencv</span>为中心的图像处理技术，大大减少了程序编写长度。微信跳一跳的简单物理外挂是一款超级好用的刷分神器，只需简简单单的操作步骤，即可实现玩家夺取好友榜第一的愿望
。在使用中，仅需将手机与物理外挂电路板分别与计算机建立通信即可，具有操作方法简单的特点。<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px; text-align: left; line-height: 150%; text-indent: 0cm;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">二、</span></span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">作品原理、电路图<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 24px; text-align: left; line-height: 150%; text-indent: -18pt;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">1.<span style='font: 7pt "Times New Roman"; margin: 0px; font-size-adjust: none; font-stretch: normal;'>&nbsp;
</span></span></span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">作品原理：<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 48px; text-align: left; line-height: 150%; text-indent: -18pt;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">1）</span></span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">图像捕捉：<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 48px; text-align: left; line-height: 150%; text-indent: 0cm;"><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">运用相关手机管理软件（如<span lang="EN-US" style="margin: 0px;">360</span>手机管家）或<span lang="EN-US" style="margin: 0px;">abd</span>进行屏幕实时捕捉。<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 24px; text-align: left; line-height: 150%;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">2</span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">）图像处理<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 48px; text-align: left; line-height: 150%; text-indent: 12pt;"><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">以<span lang="EN-US" style="margin: 0px;">vc2015</span>为开发平台，连接<span lang="EN-US" style="margin: 0px;">opencv</span>计算机视觉库，以<span lang="EN-US" style="margin: 0px;">c/c++</span>语言为主要编程语言，进行以下作品所需的图像识别算法。<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 76px; text-align: left; line-height: 150%; text-indent: -18pt;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">①<span style='font: 7pt "Times New Roman"; margin: 0px; font-size-adjust: none; font-stretch: normal;'>&nbsp;
</span></span></span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">获取棋子位置：<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 76px; text-align: left; line-height: 150%; text-indent: 24pt;"><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">事先将棋子图像进行单独截图保存，以</span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">模板匹配算法获取游戏中棋子的位置。</span><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"></span></p>

<p align="left" style="margin: 0px 0px 0px 76px; text-align: left; line-height: 150%; text-indent: -18pt;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">②<span style='font: 7pt "Times New Roman"; margin: 0px; font-size-adjust: none; font-stretch: normal;'>&nbsp;
</span></span></span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">边缘检测：<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 76px; text-align: left; line-height: 150%; text-indent: 0cm;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">&nbsp; </span></span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">首先对图片进行高斯模糊处理，以减少噪声。再用<span lang="EN-US" style="margin: 0px;">canny</span>算子进行边缘检测。<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 76px; text-align: left; line-height: 150%; text-indent: -18pt;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">③<span style='font: 7pt "Times New Roman"; margin: 0px; font-size-adjust: none; font-stretch: normal;'>&nbsp;
</span></span></span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">获取目标平台几何中心位置<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 76px; text-align: left; line-height: 150%; text-indent: 0cm;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">&nbsp;</span><span style="margin: 0px;">&nbsp; </span></span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">用<span lang="EN-US" style="margin: 0px;">Cannay</span>算子处理后的二值图像进行轮廓的寻找，并遍历轮廓，以最外层轮廓在<span lang="EN-US" style="margin: 0px;">y</span>轴方向上的最小值为中心点的<span lang="EN-US" style="margin: 0px;">y</span>轴坐标，以最外层轮廓在在<span lang="EN-US" style="margin: 0px;">x</span>轴方向上的最大值为中心点的<span lang="EN-US" style="margin: 0px;">x</span>轴坐标。<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 76px; text-align: left; line-height: 150%; text-indent: -18pt;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">④<span style='font: 7pt "Times New Roman"; margin: 0px; font-size-adjust: none; font-stretch: normal;'>&nbsp;
</span></span></span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">计算跳跃距离：<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px; text-align: left; line-height: 150%; text-indent: 69pt;"><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">通过原点坐标与目标坐标进行距离计算。<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 76px; text-align: left; line-height: 150%; text-indent: -18pt;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">⑤<span style='font: 7pt "Times New Roman"; margin: 0px; font-size-adjust: none; font-stretch: normal;'>&nbsp;
</span></span></span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">计算按压时间：<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 76px; text-align: left; line-height: 150%; text-indent: 24pt;"><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">通过测量两个屏幕大小不同的设备进行游戏是的按压时间与距离，以设备显示跳跃距离与两个设备屏幕大小的比例，计算出实际的跳跃距离。并分别建立“按压时间<span lang="EN-US" style="margin: 0px;">-</span>跳跃距离”训练集，采用线性回归算法与梯度下降算法对“按压时间<span lang="EN-US" style="margin: 0px;">-</span>跳跃距离”进行数学建模，得出“按压时间<span lang="EN-US" style="margin: 0px;">-</span>跳跃距离”数学关系式。以此通过跳跃距离计算出按压时间。<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 24px; text-align: left; line-height: 150%; text-indent: 0cm;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">3</span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">）嵌入式系统控制：<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px; text-align: left; line-height: 150%; text-indent: 28pt;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">&nbsp; </span></span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">以<span lang="EN-US" style="margin: 0px;">51</span>单片机为核心控制元件，以<span lang="EN-US" style="margin: 0px;">sg90</span>舵机对手机进行直接控制。<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 85.33px; text-align: left; line-height: 150%; text-indent: -36pt;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">（1）<span style='font: 7pt "Times New Roman"; margin: 0px; font-size-adjust: none; font-stretch: normal;'>&nbsp;
</span></span></span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">串口通信：<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 37.33px; text-align: left; line-height: 150%; text-indent: 24pt;"><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">将嵌入式系统与电脑进行<span lang="EN-US" style="margin: 0px;">USB</span>连接，在系统中采用<span lang="EN-US" style="margin: 0px;">ch340</span>芯片，实现<span lang="EN-US" style="margin: 0px;">USB</span>转<span lang="EN-US" style="margin: 0px;">TTL</span>；通过串口通信，将按压时间由计算机传送给单片机。<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 85.33px; text-align: left; line-height: 150%; text-indent: -36pt;"><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;"><span style="margin: 0px;">（2）<span style='font: 7pt "Times New Roman"; margin: 0px; font-size-adjust: none; font-stretch: normal;'>&nbsp;
</span></span></span><span lang="EN-US" style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">sg90</span><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">舵机：<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px 0px 0px 37.33px; text-align: left; line-height: 150%; text-indent: 24pt;"><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">使用积分电路和<span lang="EN-US" style="margin: 0px;">PWM</span>对<span lang="EN-US" style="margin: 0px;">sg90</span>舵机旋转角度进行控制，以此完成按压<span lang="EN-US" style="margin: 0px;"></span></span></p>

<p align="left" style="margin: 0px; text-align: left; line-height: 150%;"><span style="margin: 0px; line-height: 150%; font-family: 宋体; font-size: 12pt;">时间的操作。<span lang="EN-US" style="margin: 0px;"></span></span></p>
