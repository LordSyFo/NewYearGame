#include "widgets/HomeWidget.h"

using namespace NEG;

HomeWidget::HomeWidget(QWidget *parent) : QWidget(parent)
{
    title_ = std::make_unique<QLabel>(this);
    title_->setText("Example title");
    QFont f("Arial", 64, QFont::Bold);
    title_->setFont(f);
    title_->setStyleSheet(QStringLiteral("QLabel{color: white;}"));

    start_btn_ = std::make_unique<QPushButton>(this);
    start_btn_->setText("Start game");
    connect(start_btn_.get(), &QPushButton::released, this, &HomeWidget::HandleStartBtnPress); 

    layout_ = std::make_unique<QGridLayout>(this);

    layout_->addWidget(title_.get(), 0, 0, Qt::AlignHCenter);
    layout_->addWidget(start_btn_.get(), 1, 0, Qt::AlignHCenter);

    setLayout(layout_.get());
}

void HomeWidget::AddStartBtnCallback(StartBtnCallback_t cb)
{
    start_btn_callbacks_.push_back(cb);
}

void HomeWidget::HandleStartBtnPress()
{
    for(auto cb : start_btn_callbacks_)
        cb();
}

HomeWidget::~HomeWidget()
{
}