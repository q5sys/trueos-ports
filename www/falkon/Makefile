# $FreeBSD$

PORTNAME=	falkon
DISTVERSION=	3.0.0
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	KDE/stable/falkon/${DISTVERSION:R}/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Web browser based on WebKit engine and Qt Framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource desktop-file-utils qt:5 ssl tar:xz kde:5
USE_QT=		core dbus gui location network printsupport qml quick \
		sql webchannel webengine widgets x11extras linguist_build \
		buildtools_build qmake_build
USE_KDE=	ecm_build
USE_XORG=	xcb

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GNOMEKEYRING KWALLET
OPTIONS_SUB=	YES

KWALLET_USE=			KDE+=wallet

GNOMEKEYRING_CMAKE_BOOL=	BUILD_KEYRING
GNOMEKEYRING_USE=		GNOME=glib20
GNOMEKEYRING_LIB_DEPENDS=	libgnome-keyring.so:security/libgnome-keyring

.include <bsd.port.mk>
