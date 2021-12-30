#include <QtWidgets/QtWidgets>

#include "widgets/MainWidget.h"

#include <iostream>

using namespace NEG;

// Constructor for main widget
MainWidget::MainWidget(size_t width, size_t height, QWidget *parent) :
    QWidget(parent)
{
    // Create child widgets
    text_guess_widget_ = std::make_unique<TextGuessWidget>(this);
    text_guess_widget_->SetQuestionText("Hvem er den sejeste\n på planeten?");
    text_guess_widget_->AddOnGuessCallback([this](const QString &answer){
        std::cout << "Entered: " << answer.toStdString() << std::endl;
    });

    home_widget_ = std::make_unique<HomeWidget>(this);
    home_widget_->AddStartBtnCallback([this](){
        GoToQuestion("test question");
    });

    // Create stacked widget
    stacked_widget_ = std::make_unique<QStackedWidget>();
    stacked_widget_->addWidget(home_widget_.get());
    stacked_widget_->addWidget(text_guess_widget_.get());

    // Setup layout
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(stacked_widget_.get(), 0, 0);
    setLayout(mainLayout);

    setWindowTitle(tr("Happy new year!"));

    this->setFixedSize(QSize(width, height));

    // Set background
    QPixmap bg("resources/images/bg.jpg");
    bg = bg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bg);
    this->setPalette(palette);
}

void MainWidget::GoToQuestion(const QString& question)
{
    text_guess_widget_->SetQuestionText(question);
    stacked_widget_->setCurrentIndex(1);
}

// Destructor
MainWidget::~MainWidget()
{
}