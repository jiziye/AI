# Tesseract

##  安装
可以使用预编译（pre-built)的二进制版本或者用源码安装。
因为ubuntu官方源没有tesseract,所以需要增加PPA：
sudo add-apt-repository ppa:alex-p/tesseract-ocr
sudo apt-get update

sudo apt-get install tesseract-ocr
sudo apt-get install libtesseract-dev

默认安装英文模型，手动安装中文模型：sudo apt-get install tesseract-ocr-chi-sim

## 命令行用法
版本:  
$tesseract --version  
识别:  
$tesseract test.png test  //它对test.png进行ocr，然后把识别结果保存在test.txt里  
指定中文:  
$tesseract test.png test-l chi_sim  
$tesseract test.png test -l chi_sim pdf//默认输出格式是文本文件，我们也可以让它输出pdf  
终端输出:
$tesseract myimage.png stdout //使用stdout，可将结果直接打印到终端  
设置白名/让tesseract-OCR只识别指定内容:  
tesseract myimage.png stdout -c tessedit_char_whitelist=0123456789//只识别名单中的字符  
使用psm:
tesseract test.png test -l chi_sim  --psm 1  
修改配置文件设置白名单:  
tesseract-ocr安装路径下的tessdata/configs/digits文件，里面有tessedit_char_whitelist，将其设置成我们需要得到的识别结果。  
如tesseract 配置里改成只识别 0-9 数字，在tessdata/configs/digits 的文本文件中：tessedit_char_whitelist 0123456789  
$tesseract  imagename  outputbase  digits  
安装路径：
tessdata/configs在/usr/share/tesseract-ocr下

## 编译tesseract demo
make:  g++ -o myprogram myprogram.cpp -llept -ltesseract