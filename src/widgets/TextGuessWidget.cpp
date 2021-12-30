#include "widgets/TextGuessWidget.h"

using namespace NEG;

TextGuessWidget::TextGuessWidget(QWidget *parent) : QWidget(parent)
{
    // Create and setup label
    text_label_ = std::make_unique<QLabel>(this);
    QFont f("Arial", 32, QFont::Bold);
    text_label_->setFont(f);
    text_label_->setStyleSheet(QStringLiteral("QLabel{color: white;}"));

    // Create and setup text edit field
    line_edit_ = std::make_unique<QLineEdit>(this);
    line_edit_->setFixedSize(QSize(parent->width() / 2, 30));

    // Create button
    push_btn_ = std::make_unique<QPushButton>(this);
    push_btn_->setText("Guess");
    push_btn_->setFixedSize(QSize(parent->width() / 2, 50));
    connect(push_btn_.get(), &QPushButton::released, this, &TextGuessWidget::HandleBtnPress); 

    // Create and setup layout
    layout_ = std::make_unique<QGridLayout>(this);
    layout_->addWidget(text_label_.get(), 0, 0, Qt::AlignHCenter);
    layout_->addWidget(line_edit_.get(), 1, 0, Qt::AlignHCenter);
    layout_->addWidget(push_btn_.get(), 2, 0, Qt::AlignHCenter);

    setLayout(layout_.get());
}

void TextGuessWidget::HandleBtnPress()
{
    for(auto cb : on_guess_callbacks_)
        cb(line_edit_->text());
}

void TextGuessWidget::SetQuestionText(const QString &question)
{
    text_label_->setText(question);
}

void TextGuessWidget::AddOnGuessCallback(OnGuessCallback_t func)
{
    on_guess_callbacks_.push_back(func);
}

TextGuessWidget::~TextGuessWidget()
{

}