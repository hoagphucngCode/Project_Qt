#ifndef IMAGE_PROVIDER_H
#define IMAGE_PROVIDER_H

#include <QObject>
#include <QQuickImageProvider>

class ImageProvider : public QQuickImageProvider
{
	Q_OBJECT
public:
	ImageProvider();
	QPixmap requestPixmap(const QString &id, QSize* size, const QSize &requestSize) override;
	QString addImage(QString id, QImage &img);
private:
	QMap<QString, QPixmap> objMap;
};

#endif // IMAGE_PROVIDER_H
