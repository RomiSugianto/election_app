#ifndef FUNCTION_H
#define FUNCTION_H
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "dialog_login.h"
#include "dialog_complete.h"
#include "dialog_admin.h"
#include "QByteArray"
#include "QBuffer"
#include "QFileDialog"

class Function
{
public:
    QPixmap getImageJp()
    {
        QPixmap pixImg;
        QString querySelect = "SELECT imgData FROM image where iOwn = 1";
        QSqlQuery query;
        QByteArray byteImg;
        query.prepare(querySelect);

        if(query.exec())
        {
            while(query.next())
            {
                byteImg = query.value("imgData").toByteArray();
                pixImg.loadFromData(byteImg);
                break;
            }
        }

        return pixImg;
    }

    QPixmap getImageNa()
    {
        QPixmap pixImg;
        QString querySelect = "SELECT imgData FROM image where iOwn = 2";
        QSqlQuery query;
        QByteArray byteImg;
        query.prepare(querySelect);

        if(query.exec())
        {
            while(query.next())
            {
                byteImg = query.value("imgData").toByteArray();
                pixImg.loadFromData(byteImg);
                break;
            }
        }

        return pixImg;
    }
};

#endif // FUNCTION_H
