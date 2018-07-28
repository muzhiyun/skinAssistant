#ifndef ZXML_H
#define ZXML_H

#define XMLDOCTYPE "SkinToolProject"
#define XMLVERSION "0.2.3"

#include <QDebug>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QtXml/QDomDocument>
#include <QList>

struct XmlNumber
{
    QString value;
    QString name;
    QString Roman;
};

struct XmlNumberInfo
{
   QList<XmlNumber> numberList;
};

typedef struct Position
{
    QString X;
    QString Y;
    QString Width;
    QString Height;
}XPostoin;
typedef struct Text
{
    QString TextAlign;
    QString TextDistance;
    QString TextID;
    QString NormalTextColor;
    QString FocusTextColor;
    QString DisableTextColor;
}XText;

typedef struct Navigation
{
    QString Up;
    QString Down;
    QString Left;
    QString Right;
}XNavigation;

typedef struct StaticWndProperties
{
    QString NormalBitmapID;
    QString FocusBitmapID;
    QString DisabledBitmapID;
    QString NormalBgColor;
    QString FocusBgColor;
    QString DisabledBgColor;
    QString Clone;
    QString BgState;
}XStaticWndProperties;

typedef struct Wnd
{
    QString Name;
    QString ParentName;
    struct Wnd* parentWnd;
    XPostoin postion;
    XText   text;
    XNavigation navigtion;
    XStaticWndProperties staticWndProperties;
}XWnd;

typedef struct WndList{
    QList<Wnd> wndList;
}XWndList;
typedef struct GWnd{
    QString Name;
    int XPos;
    int YPos;
    int Width;
    int Height;
    QString GWIN;
    WndList wndlist;
}XGWnd;

typedef struct GWndList
{
    QList<GWnd> gwndlist;
}XGWndList;


typedef struct SkinToolProject
{
   QString Version;
   QString Build;
   QString SizePanel;
   XGWndList gwndList;
}XSkinToolProject;

class ZXml
{
public:
  ZXml();

  QDomElement xmlRead(QIODevice *device);
  QString errorString() const;
  void xmlWrite(QIODevice *device);
  XSkinToolProject * getSkinToolProject();
  bool changeSave(QIODevice *device);
  QDomElement xmlCreateNode(QString tagName);
  QDomAttr xmlCreateAttribute(QString name);
public:
  void readXmlContents();
  void readNumber();
  XmlNumberInfo* getNumberInfo();
  QString readName();
  QString readRoman();
  QString readValue();
  void readVersion();
  void readBuild();
  void readGWndList();
  void readGWnd();
  void readWndList(GWnd *pgwnd);
  void readWnd(GWnd *pgwnd);
private:
  QXmlStreamReader xml;
  QXmlStreamWriter wXml;
  XmlNumberInfo m_numberInfo;
  SkinToolProject m_project;
  QDomDocument m_doc;
};

#endif // ZXML_H