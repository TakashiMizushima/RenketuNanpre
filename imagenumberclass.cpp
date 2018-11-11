#include "imagenumberclass.h"

imagenumberclass::imagenumberclass()
{

}
void imagenumberclass::numimageload()
{
    for(int i=0;i<9;i++)
    {
        numim[i].load("./num/0"+QString::number(i)+".jpg");
    }
}
void imagenumberclass::MainWindowSet(MainWindow *mmain)
{
    mainwin=mmain;
}
void imagenumberclass::paperimageload()
{
    QString fileName = QFileDialog::getOpenFileName(mainwin,QObject::tr("Open Data"), QObject::tr(""),QObject::tr("jpaeg (*.jpg);;All Files (*)"));
    if(fileName==""){return;}
    paper.load(fileName);
}
void imagenumberclass::matchnumber()
{
    arrcnt=0;
    for(int i=0;i<paper.width();i++)
    {
        for(int j=0;j<paper.height();j++)
        {
            int gray=0;
            int gray2=0;

            for(int a=0;a<9;a++)
            {
                int matchcnt=0;
                int totalcnt=numim[a].width()*numim[a].height();

                for(int m=0;m<numim[a].width();m++)
                {

                    for(int n=0;n<numim[a].height();n++)
                    {
                        /*if(i+m<paper.width() && j+n<paper.height())
                        {
                            //QRgb color=paper.pixel(i,j);
                            //QRgb color2=numim[a].pixel(m,n);
                            //gray = qRed(color) + qGreen(color) + qBlue(color);
                            gray/=3;
                            //gray2 = qRed(color2) + qGreen(color2) + qBlue(color2);
                            gray2/=3;
                            if(gray==gray2){matchcnt++;}
                        }
*/
                    }
                 }
                if(matchcnt/totalcnt>=0.5)
                {
                    if(arrcnt<81)
                    {
                        numarr[arrcnt]=a+1;
                        arrcnt++;
                        i+=numim[a].width();
                    }
                }

            }

        }
    }
}
void imagenumberclass::filesave()
{
    FILE *fp=fopen("numdata.txt","w");
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            fprintf(fp,"%d",numarr[i*9+j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}
