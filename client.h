#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include<QTcpSocket>
#include<QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QWidget
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();
private slots:
    void requestMessage();
    void showError();
    void readMessage();

private:
    Ui::Client *ui;
    QTcpSocket *clientSocket = nullptr;
    QDataStream in;
};
#endif // CLIENT_H
