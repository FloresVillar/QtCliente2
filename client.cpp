#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    //inicializar clientSocket
    clientSocket =new QTcpSocket(this);
 //inicializar in
    in.setDevice(clientSocket);
    connect(ui->pBtn_close,&QAbstractButton::clicked,this,&QWidget::close);
    connect(clientSocket,&QIODevice::readyRead,this,&Client::readMessage);
    connect(ui->pBtn_connect,&QAbstractButton::clicked,this,&Client::requestMessage);
}

Client::~Client()
{
    delete ui;
}
/**
 * @brief Client::requesMessage
 *este slot inicia la comunicacion con el servidor
 *y se solicita un mensaje
 */
void Client::requestMessage()
{
    qDebug()<<"inciando requestMessage() ";
    QString ipAddres = ui->lEdit_ip->text();
    QString port = ui->lEdit_port->text();
    qDebug()<<"ipAddress: "<<ipAddres<<" ,: "<<port;
    clientSocket->connectToHost(ipAddres,port.toInt());//si esto fallara....

    qDebug()<<"saliendo de requestMessage";

}
/**
 * @brief Client::showError
 *
 */
void Client::showError()
{

}
/**
 * @brief Client::readMessage
 * el cliente inicia la lectura del mensaje que ha llegado al cliente
 */
void Client::readMessage()
{
    qDebug()<<"iniciando readMessage() ";
    in.startTransaction();
    qDebug()<<"finalizanco readMessage()";
    QString message=" ";
    in>>message;
    if(!in.commitTransaction()){
        qDebug()<<"error";
    }
    qDebug()<<"mensaje: "<< message;
    ui->lbl_message->setText(message);

}

