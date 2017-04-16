#ifndef ENGINEDATAELEMENT_H
#define ENGINEDATAELEMENT_H

#include <QString>
class EngineDataElement
{
public:
    EngineDataElement(const int count , const QString text1 , const QString text2 , const QString text3 , const QString text4 , const QString text5);

    int getCount()const;
    void setCount(int nValue);

    QString getText1()const;
    void setText1(QString nValue) ;

    QString getText2()const;
    void setText2(QString nValue) ;

    QString getText3()const;
    void setText3(QString nValue) ;

    QString getText4()const;
    void setText4(QString nValue) ;

    QString getText5()const;
    void setText5(QString nValue) ;

private:
    int     m_Count;
    QString m_Text1;
    QString m_Text2;
    QString m_Text3;
    QString m_Text4;
    QString m_Text5;

};

#endif // ENGINEDATAELEMENT_H
