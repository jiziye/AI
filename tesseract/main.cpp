#include<tesseract/baseapi.h>
#include<leptonica/allheaders.h>
#include<iostream>

int main()
{
    char *outText;
    
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    if(api->Init(NULL, "eng")){
        fprintf(stderr, "cloud not initialize tesseract. \n");
        exit(1);
    }

    Pix *image = pixRead("./test.png");
    api->SetImage(image);
    outText = api->GetUTF8Text();
    printf("OCR output: \n %s ",outText);

    api->End();
    delete[] outText;
    pixDestroy(&image);

    return 0;

}
