#ifndef USER_H
#define USER_H
#include <QMainWindow>

class UserData
{
private :
    int NOT_SETTLE_YET = 0;
    int ALREADY_SETTLE_YET = 1;
    QString NOT_SETTLE_YET_EN = "Not Settle Yet";
    QString ALREADY_SETTLE_YET_EN = "Already Settle";

    QString setStatusString(int status)
    {
        if(status == NOT_SETTLE_YET)
            return NOT_SETTLE_YET_EN;
        if(status == ALREADY_SETTLE_YET)
            return ALREADY_SETTLE_YET_EN;
    }


private :
    int userId;
    QString szName;
    QString szAddress;
    int iStatus;
    QString szStatus;

public :
    void setUserId(int userId)
    {
        this->userId = userId;
    }
    void setName(QString szName)
    {
        this->szName = szName;
    }
    void setAddress(QString szAddress)
    {
        this->szAddress = szAddress;
    }
    void setStatusAsInt(int iStatus)
    {
        this->iStatus = iStatus;
        this->szStatus = setStatusString(iStatus);
    }

    int getUserId()
    {
        return this->userId;
    }
    QString getName()
    {
        return this->szName;
    }
    QString getAddress()
    {
        return this->szAddress;
    }
    int getStatusAsInt()
    {
        return this->iStatus;
    }

    QString getStatus()
    {
        return this->szStatus;
    }
};


#endif // USER_H
