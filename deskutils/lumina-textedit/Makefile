# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina-textedit
PORTVERSION=	1.4.2
PORTREVISION=	201803131031
CATEGORIES=	deskutils

MAINTAINER=	jt@ixsystems.com
COMMENT=	Plaintext editor from the Lumina Desktop

LICENSE=	BSD3CLAUSE

CONFLICTS_INSTALL=	lumina-1.2.*

OPTIONS_DEFINE=	I18N
OPTIONS_DEFAULT=	I18N
OPTIONS_SUB=	yes

I18N_DESC=	Install localization files

.include <bsd.port.options.mk>

MAKE_JOBS_UNSAFE=yes

USE_QT=		core gui widgets network svg printsupport \
		buildtools_build x11extras concurrent multimedia
USES=		qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	lumina
GH_TAGNAME=	e1dae8c03e02869f752ca6210ea276e32545f11a
WRKSRC_SUBDIR=	src-qt5/desktop-utils/${PORTNAME}

.if${PORT_OPTIONS:MI18N}
USE_QT+=	linguist_build
QMAKE_ARGS+=CONFIG+=WITH_I18N
.endif

.include <bsd.port.mk>
