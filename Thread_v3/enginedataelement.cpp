#include "enginedataelement.h"

EngineDataElement::EngineDataElement(const int count, const QString text1, const QString text2, const QString text3, const QString text4, const QString text5)
    : m_Count(count)
    , m_Text1(text1)
    , m_Text2(text2)
    , m_Text3(text3)
    , m_Text4(text4)
    , m_Text5(text5)
{

}

int EngineDataElement::getCount()const
{
    return m_Count;
}

void EngineDataElement::setCount(int nValue)
{
    m_Count = nValue;
}

QString EngineDataElement::getText1()const
{
    return m_Text1;

}

void EngineDataElement::setText1(QString nValue)
{
    m_Text1 = nValue;
}

QString EngineDataElement::getText2()const
{
    return m_Text2;
}

void EngineDataElement::setText2(QString nValue)
{
    m_Text2 = nValue;
}

QString EngineDataElement::getText3()const
{
    return m_Text3;
}

void EngineDataElement::setText3(QString nValue)
{
    m_Text3 = nValue;
}

QString EngineDataElement::getText4()const
{
    return m_Text4;
}

void EngineDataElement::setText4(QString nValue)
{
    m_Text4 = nValue;
}

QString EngineDataElement::getText5()const
{
    return m_Text5;
}

void EngineDataElement::setText5(QString nValue)
{
    m_Text5 = nValue;
}



