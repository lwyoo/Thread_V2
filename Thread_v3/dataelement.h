#ifndef DATAELEMENT_H
#define DATAELEMENT_H

#include <QString>

class DataElement
{
public:
    DataElement(const int count , const QString text1 , const QString text2);

    int getCount()const;
    void setCount(int nValue);

    QString getText1()const;
    void setText1(QString nValue) ;

    QString getText2()const;
    void setText2(QString nValue) ;
private:
    int     m_Count;
    QString m_Text1;
    QString m_Text2;
};

#endif // DATAELEMENT_H
