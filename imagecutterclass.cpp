#include "imagecutterclass.h"

imagecutterclass::imagecutterclass()
{

}
void imagecutterclass::templateimage(QString paperfilename,QString cutterfilename)
{
    cv::Mat img= cv::imread(paperfilename.toStdString().c_str());
    img2= cv::imread(cutterfilename.toStdString().c_str());
    cv::Mat gray;
    cv::Mat result_img;
    cv::cvtColor(img,gray,CV_BGR2GRAY);
    cv::threshold(gray, gray, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    cv::Point2f center = cv::Point2f(static_cast<float>(img.cols / 2),static_cast<float>(img.rows / 2));
    cv::blur(img2, img2, cv::Size(2,2));
    for(int i=0;i<6;i++)
    {
    double degree=0;
    double scale=1.0;
    if(i==1 || i==2 || i==3){
       degree = 0.12;  // 回転角度
       scale = 1.0;    // 拡大率
    }
    if(i==4){
       degree = -0.48;  // 回転角度
       scale = 1.0;    // 拡大率
    }
    if(i==5){
        degree = -0.12;  // 回転角度
        scale = 1.0;    // 拡大率
     }
     // アフィン変換行列
     cv::Mat affine;
     cv::getRotationMatrix2D(center, degree, scale).copyTo(affine);
     cv::warpAffine(img, img, affine, img.size(), cv::INTER_CUBIC);
      // テンプレートマッチング
      cv::matchTemplate(img, img2, result_img, CV_TM_CCOEFF_NORMED);

      // 最大のスコアの場所を探す
      for(int y=0;y<result_img.rows;y++)
      {
          for(int x=0;x<result_img.cols;x++)
          {
              if(result_img.at<float>(y,x)>0.70f)
              {
                  detected_point.push_back(cv::Point(x,y));
              }
          }
      }
      /*
      for(auto it=detected_point.begin();it!=detected_point.end();it++)
      {
          cv::rectangle(img,*it,cv::Point(it->x+img2.cols,it->y+img2.rows), cv::Scalar(0,255,255), 2,8,0);
      }*/
    }
    cv::imwrite("./done.jpg",img);

}
void imagecutterclass::cutimagesave()
{
    paper.load("./done.jpg");
    QSize siz(img2.cols,img2.rows);
    int i=0;
    QImage *cutimg=new QImage(siz, QImage::Format_ARGB32_Premultiplied);
    for(auto it=detected_point.begin();it!=detected_point.end();it++)
    {
        i++;
        QPainter pr(cutimg);
        ///(0,0,img,(*it).x,(*it).y());
        pr.drawImage(0,0,paper,(*it).x,(*it).y);
        cutimg->save(QString("./data/data")+QString::number(i)+QString(".jpg"));
        //cv::rectangle(img,*it,cv::Point(it->x+img2.cols,it->y+img2.rows), cv::Scalar(0,255,255), 2,8,0);
    }

    //pr.drawImage(0,0,paper,(spos.x()-drawpos.x())/scalecount,(spos.y()-drawpos.y())/scalecount);
    //cutfilewrite();
    return;
}
