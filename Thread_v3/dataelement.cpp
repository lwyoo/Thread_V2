#include "dataelement.h"

DataElement::DataElement(const int count, const QString text1, const QString text2)
    :m_Count(count)
    , m_Text1(text1)
    , m_Text2(text2)
{

}

int DataElement::getCount() const
{
    return m_Count;
}

void DataElement::setCount(int nValue)
{
    m_Count = nValue;
}

QString DataElement::getText1()const
{
    return m_Text1;

}

void DataElement::setText1(QString nValue)
{
    m_Text1 = nValue;
}

QString DataElement::getText2()const
{
    return m_Text2;
}

void DataElement::setText2(QString nValue)
{
    m_Text2 = nValue;
}
