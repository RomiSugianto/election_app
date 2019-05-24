#ifndef USER_H
#define USER_H
#include <QMainWindow>

class UserData
{
private :
    int userId;
    QString szName;
    QString szAddress;
    int iStatus;
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
    void setStatus(int iStatus)
    {
        this->iStatus = iStatus;
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
    int getStatus()
    {
        return this->iStatus;
    }
};


#endif // USER_H
