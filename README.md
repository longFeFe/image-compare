## 安装 opencv-2.4.13.5
win下载直接安装  
https://jaist.dl.sourceforge.net/project/opencvlibrary/opencv-win/2.4.13/opencv-2.4.13.5-vc14.exe  
linux下载源码  
https://jaist.dl.sourceforge.net/project/opencvlibrary/opencv-unix/2.4.13/opencv-2.4.13.zip  

## linux编译安装opencv-2.4.13.5
cd opencv-2.4.13.5  
mkdir opencv-2.4.13.5 
cmake ..  
make -j4  
make install

## Windows平台编译方法
修改 CMakeLists.txt 中的opencv安装路径  
打开 VS开发人员命令 控制台  
cd images-compare/build  
cmake ..  
cmake --build . --config Release   

## Linux平台编译方法    
cd images-compare/build  
cmake ..  
make 



## 测试
cd images-compare/bin  
./test_compare  sample.jpg  reference.jpg
