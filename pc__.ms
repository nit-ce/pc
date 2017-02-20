.nr LL 6.5i
.nr PO .85i
.ds fa.cl "#973
.fp 8 HD IRHoma
.fp 18 FX IRNazanin
.bd FX 2
.fp 19 IO IRNazaninBold
.cs IO 24
.fa.ffont IO
.fa.ffont FX
.fa.ffont HD
.rn SH SH_
.de SH
.\"	sp
.\"	nr w \\n(.l
.\"	SH_ "\m[#fff]\h'1n'\\$1\m[\\*[fa.cl]]\h'|0'\v'-1n'\D'P -\\nwu 0 0 -1v \\nwu 0 0 1v'\v'1n'"
.	ta \\n(.luR
.	SH_ "\s+9\\$1\s-9"
.	sp
..
.rn TL TL_
.de TL
.	RT
.	>>
\m[\\*[fa.cl]]\D'P \\n(LLu 0 0 2i -\\n(LLu 0'\m[]
.	<<
.	nf
.	cl #f
.	ft HD
.	ta 2mL \n(.luR
	\s8\\$2\s0	\s5\v'-1.5i'\\$3\v'1.5i'\s0
.	cl
.	ft P
.	sp -1
.	TL_ "\m[#f]\s+9\\$1\s0\m[]"
..
.de FT.pg
.	if \\n[fa.pg]=1 'tl '''\m[\\*[fa.cl]]\f(HD\>%\<\fP\m[]'
.	el 'sp
..
.rn IP IP_
.de IP
.	sp
.	IP_ "\f(HD\m[\\*[fa.cl]]\\$1\m[]\fP" \\$2
..
.nr boxborder 1n
.de boxbeg
.	br
.	di boxdiv
..
.de boxend
.	br
.	di
.	nr boxw \\n(.lu
.	nr boxh \\n(dnu
.	ne \\n[boxh]u
.	mk boxtop
.	>>
.	nf
\m[#fdfffb]\D'P \\n[boxw]u 0 0 \\n[boxh]u -\\n[boxw]u 0 0 -\\n[boxh]u'\m[]\
\D'p \\n[boxw]u 0 0 \\n[boxh]u -\\n[boxw]u 0 0 -\\n[boxh]u'
.	sp -.5
.	in \\n[boxborder]u
.	boxdiv
.	in
.	sp |\\n[boxtop]u+\\n[boxh]u+1v
.	<<
.	fi
..
.de tblnf
.	>>
.	ft CB
.	ps \\n(PS-3
.	vs \\n(PS+4
.	nf
..
.de iobeg
.	LP
.	KS
.	nr VS -9
.	nr iowid \\n(LLu/2u
.	tblbeg \\n[iowid] 0
.	tblbox 1 1 1
.	tblmac fa.tblfc fa.tblfc
.	tblrow "\f(HDورودی\fP" "\f(HDخروجی\fP"
.	tblmac tblnf tblnf
.	tblcol 1
.	vs -3
.	ft IO
..
.de iocut
.	tblcol 2
.	vs -3
.	ft IO
..
.de ioend
.	tblend
.	nr VS +9
.	KE
..
.rn tblrst _tblrst
.de tblrst
.	_tblrst
.	ps \\n(PS
.	vs \\n(VS
..
.de dcbeg
.	KS
.	tblbeg \\$1 0
.	tblbox 0 0 0
.	tblmac fa.tblfb fa.tblfb
.	tblcol 1
..
.de dccut
.	tblcol 2
..
.de dcend
.	tblend
.	KE
..
.\" plain english text
.de ccbeg
.	br
.	ev phd.en
.	RT
.	ps \\n(PSp-2p
.	vs \\n(PSp+2p
.	>>
.	ft CB
.	cl #335
.	nf
.	kn 0
.	lg 0
.	sp
.	in 1m
..
.de ccend
.	lg 1
.	kn 1
.	br
.	ev
..
.de un
\s-1\>\fR\\$1\fP\<\s+1
..
.chop un
.de fa.tblcc
.	>>
.	ad l
.	ft CB
..
.EQ
grfont CMR
gfont CMMI
define sum @{vcenter roman "\N'summationdisplay'"}@
define tsum @{vcenter roman "\N'summationtext'"}@
define prod @{vcenter roman "\N'productdisplay'"}@
define tprod @{vcenter roman "\N'producttext'"}@
define small @size -4@
chartype ord .
chartype bin \(rs
.EN
