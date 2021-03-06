# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	concurrencykit
PORTVERSION=	0.6.0
CATEGORIES=	devel
MASTER_SITES=	http://concurrencykit.org/releases/ \
		http://repnop.org/releases/
DISTNAME=	ck-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Lock-free data structures for high performance concurrent systems

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 sparc64
BROKEN_armv6=		fails to configure: Finding suitable compiler........failed  [not found]
BROKEN_armv7=		fails to configure: Finding suitable compiler........failed  [not found]
BROKEN_powerpc64=	fails to link: skipping incompatible /usr/lib/libgcc.a when searching for -lgcc

OPTIONS_DEFINE=		RTM VMAPACK
OPTIONS_DEFAULT=	VMAPACK

RTM_DESC=	Restricted Transactional Memory (x86_64 only)
VMAPACK_DESC=	Enable pointer packing

RTM_CONFIGURE_ON=	--enable-rtm
VMAPACK_CONFIGURE_ON=	--enable-pointer-packing

USES=		pkgconfig
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--mandir=${PREFIX}/man

TEST_TARGET=	check

PLIST_SUB+=	VERSION=${PORTVERSION}

post-extract:
	${REINPLACE_CMD} -e 's|PKGCONFIG_DATA=@LIBRARY@|PKGCONFIG_DATA=${PREFIX}/libdata/|g' \
	${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libck.so.${PORTVERSION}

.include <bsd.port.mk>
