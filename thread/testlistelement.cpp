#include "testlistelement.h"
#include <QDebug>
TestListElement::TestListElement(const int count, const QString text1)
    :  m_count(count)
    , m_text1(text1)
{
//    qDebug() << "count + text";

}

TestListElement::TestListElement(const int count, const QString text1, const QString text2, const QString text3)
    :  m_count(count)
    , m_text1(text1)
    , m_text2(text2)
    , m_text3(text3)
{
//    qDebug() << "count + text + text + text";
}

TestListElement::TestListElement(const int count, const QString text1, const QString iconUrl)
    :  m_count(count)
    , m_text1(text1)
    , m_iconUrl(iconUrl)
{
    //    qDebug() << "count + text + icon";
}

TestListElement::TestListElement(const int count, const QString text1, const QString text2, const QString text3, const QString iconUrl)
    :  m_count(count)
    , m_text1(text1)
    , m_text2(text2)
    , m_text3(text3)
    , m_iconUrl(iconUrl)
{

}

int TestListElement::getCount() const
{
    return m_count;
}

void TestListElement::setCount(int nValue)
{
    if (m_count != nValue)
    {
        m_count = nValue;
    }
}

QString TestListElement::getText1() const
{
    return m_text1;
}

void TestListElement::setText1(QString nValue)
{
    if (m_text1 != nValue)
    {
        m_text1 = nValue;
    }
}

QString TestListElement::getText2() const
{
    return m_text1;
}

void TestListElement::setText2(QString nValue)
{
    if (m_text2 != nValue)
    {
        m_text2 = nValue;
    }
}

QString TestListElement::getText3() const
{
    return m_text1;
}

void TestListElement::setText3(QString nValue)
{
    if (m_text3 != nValue)
    {
        m_text3 = nValue;
    }
}

QString TestListElement::getIconUrl() const
{
    return m_iconUrl;
}

void TestListElement::setIconUrl(QString nValue)
{
    if (m_iconUrl != nValue)
    {
        m_iconUrl = nValue;
    }
}
