--- pvmnet/if_pvmnet.c.orig	2014-10-02 22:19:21.000000000 +0400
+++ pvmnet/if_pvmnet.c	2014-10-02 22:21:10.000000000 +0400
@@ -364,12 +364,20 @@
 		for (offset = io_get_rcv_offset(sc);
 		    (size = io_get_packet_size(sc, offset)); offset += FULL_PACKET_SIZE(size)) {
 			if (size > ETHER_MAX_LEN) {
+#if __FreeBSD_version >= 1100036
+				if_inc_counter(ifp, IFCOUNTER_IERRORS, 1);
+#else
 				ifp->if_ierrors++;
+#endif
 				continue;
 			}
 			m = m_getcl(M_NOWAIT, MT_DATA, M_PKTHDR);
 			if (m == NULL) {
+#if __FreeBSD_version >= 1100036
+				if_inc_counter(ifp, IFCOUNTER_IERRORS, 1);
+#else
 				ifp->if_ierrors++;
+#endif
 				continue;
 			}
 			m->m_pkthdr.rcvif = ifp;
@@ -379,7 +387,11 @@
 			m->m_pkthdr.len = m->m_len = size;
 			io_read_data(sc, offset, m);
 
+#if __FreeBSD_version >= 1100036
+			if_inc_counter(ifp, IFCOUNTER_IPACKETS, 1);
+#else
 			ifp->if_ipackets++;
+#endif
 
 			PVMNET_UNLOCK(sc);
 			(*ifp->if_input)(ifp, m);
@@ -538,7 +550,11 @@
 			io_notify_sndbuf_full(sc);
 			break;
 		}
+#if __FreeBSD_version >= 1100036
+		if_inc_counter(ifp, IFCOUNTER_OPACKETS, 1);
+#else
 		ifp->if_opackets++;
+#endif
 		BPF_MTAP(ifp, m);
 		m_freem(m);
 	}
