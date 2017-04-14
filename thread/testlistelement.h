#ifndef TESTLISTELEMENT_H
#define TESTLISTELEMENT_H

#include <QString>
class TestListElement
{
public:
    /*
     * 숫자 + 그냥 문자 1개
     * 숫자 + 그냥 문자 3개
     * 숫자 + 문자1 + icon 1
     */

    TestListElement(const int count , const QString text1); //숫자 + 그냥 문자 1개
    TestListElement(const int count , const QString text1 , const QString text2 , const QString text3 ); //숫자 + 그냥 문자 3개
    TestListElement(const int count , const QString text1 , const QString iconUrl); //숫자 + 문자1 + icon 1
    TestListElement(const int count , const QString text1 , const QString text2 , const QString text3 , const QString iconUrl);

    int getCount() const ;
    void setCount(int nValue);

    QString getText1()const ;
    void setText1(QString nValue);

    QString getText2()const ;
    void setText2(QString nValue);

    QString getText3()const ;
    void setText3(QString nValue);

    QString getIconUrl()const ;
    void setIconUrl(QString nValue);




private:
    int m_count;
    QString m_text1;
    QString m_text2;
    QString m_text3;
    QString m_iconUrl;
    //
};

#endif // TESTLISTELEMENT_H
