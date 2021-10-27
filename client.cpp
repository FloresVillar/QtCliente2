#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    connect(ui->pBtn_close,&QAbstractButton::clicked,this,&QWidget::close);
    connect(clientSocket,&QIODevice::readyRead,this,&Client::readMessage);
}

Client::~Client()
{
    delete ui;
}

void Client::requesMessage()
{

}

void Client::showError()
{

}

void Client::readMessage()
{

}

