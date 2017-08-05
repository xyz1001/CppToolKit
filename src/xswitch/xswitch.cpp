#include "xswitch.h"

#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

class XSwitch::XSwitchImpl {
public:
    XSwitchImpl(const XSwitchOption &option)
        : option_(option) {

        size_hint_ = SizeHint();
        box_rect_ = QRect(option_.slider_margin < 0 ? -option_.slider_margin : 0,
                                          (size_hint_.height() - option_.box_height) / 2,
                                          option_.box_width, option_.box_height);
        slider_rect_ = QRectF(option_.slider_margin > 0 ? option_.slider_margin : 0,
                                       (size_hint_.height() - option_.slider_diameter) / 2,
                                       option_.slider_diameter, option_.slider_diameter);
        slide_end_ = option_.box_width - option_.slider_margin * 2 - option_.slider_diameter;
    }

    QSize SizeHint() {
        int w = std::max(static_cast<int>(option_.box_width),
                         option_.box_width - option_.slider_margin * 2);
        int h = std::max(option_.slider_diameter, option_.box_height);
        return QSize(w, h);
    }

    XSwitchOption option_;
    bool is_turn_on_ = false;
    int slider_offset_= 0;
    QSize size_hint_;
    QRect box_rect_;
    QRectF slider_rect_;
    uint16_t animation_duration_ = 100;
    int slide_start_ = 0;
    int slide_end_ = 0;
};

XSwitch::XSwitch(const XSwitchOption &option, QWidget *parent)
    : QAbstractButton(parent),
      pimpl_(new XSwitchImpl(option)),
      animation_(new QPropertyAnimation(this, "slider_offset", this))
{

    animation_->setDuration(pimpl_->animation_duration_);
}

XSwitch::~XSwitch() = default;

int XSwitch::GetOffset() const {
    return pimpl_->slider_offset_;
}

void XSwitch::SetOffset(int offset) {
    pimpl_->slider_offset_ = offset;
    update();
}

void XSwitch::paintEvent(QPaintEvent */*e*/) {
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QBrush box_brush;
    QBrush slider_brush;
    if (isEnabled()) {
        box_brush = pimpl_->is_turn_on_ ? pimpl_->option_.turn_on_box_brush : pimpl_->option_.turn_off_box_brush;
        slider_brush = pimpl_->option_.slider_brush;
    } else {
        box_brush = pimpl_->option_.disable_box_brush;
        slider_brush = pimpl_->option_.disable_slider_brush;
        pimpl_->slider_offset_ = 0;
    }
    painter.setBrush(box_brush);
    painter.drawRoundedRect(pimpl_->box_rect_, pimpl_->option_.box_height/2, pimpl_->option_.box_height/2);
    painter.setBrush(slider_brush);
    painter.drawEllipse(QRectF(pimpl_->slider_rect_.x() + pimpl_->slider_offset_, pimpl_->slider_rect_.y(),
                               pimpl_->slider_rect_.width(), pimpl_->slider_rect_.height()));
}

void XSwitch::mouseReleaseEvent(QMouseEvent *e) {
    if (e->button() & Qt::LeftButton) {
        pimpl_->is_turn_on_ = !(pimpl_->is_turn_on_);
        animation_->stop();
        animation_->setStartValue(GetOffset());

        if (pimpl_->is_turn_on_) {
            animation_->setEndValue(pimpl_->slide_end_);
        } else {
            animation_->setEndValue(pimpl_->slide_start_);
        }

        animation_->start();
    }

    QAbstractButton::mouseReleaseEvent(e);
}

void XSwitch::enterEvent(QEvent *e) {
    setCursor(Qt::PointingHandCursor);
    QAbstractButton::enterEvent(e);
}

QSize XSwitch::sizeHint() const {
    return pimpl_->SizeHint();
}
