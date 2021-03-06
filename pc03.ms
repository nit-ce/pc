.\" PSTITLE: NIT Wednesday Programming Problem \- PC03
.so pc__.ms
.nr fa.pg 0
.ds fa.cl "#977
.TL "چهارشنبه‌ی سوم\&" "مسئله‌ی برنامه‌نویسی \m[#8f4]چهارشنبه\m[]\&" "می‌خواهیم بهترین باشیم..."
.sp 1
.LP
رقابت چهارشنبه‌ی جاری با انتشار این مسئله آغاز می‌شود.
فرستادن جواب‌ها مشابه پنج‌شنبه‌های سخت است؛
مستند \*[en http://nit.rudi.ir/ctsubmit.pdf] گام‌های
لازم برای فرستادن جواب و دیدن نتیجه‌ی ارزیابی آن را شرح می‌دهد.
در ستون آخر نتایج، به ازای هر نمونه‌ی ورودی یک حرف نمایش داده
می‌شود.  در این ستون حرف \*[en P] به معنی خروجی با شکل مناسب،
حرف \*[en F] به معنی خروجی اشتباه،
حرف \*[en T] به معنی خاتمه نیافتن جواب در زمان مجاز دو ثانیه،
حرف \*[en E] به معنی خطای ترجمه و
حرف \*[en R] به معنی خطای زمان اجرا است.

.sp |6.5i
.nr VS -6
.tblbeg 4i 0
.	tblbox 1 1 1
.	tblmac fa.tblfc fa.tblfc
.	tblrow "\f(FXحرف‌های وارونه\fP" "\f(FXعنوان مسئله\fP"
.	tblrow "\*[en pc03]" "\f(FXشناسه‌ی مسئله\fP"
.	tblrow "\*[num 3] از \*[num 9]" "\f(FXسختی مسئله\fP"
.	tblrow "ساعت \*[num 16]    \*[num 1396/2/6\^]" "\f(FXزمان شروع\fP"
.	tblrow "ساعت \*[num 16]    \*[num 1396/2/16]" "\f(FXزمان پایان\fP"
.tblend
.nr VS +6

.LP
.sp |9.5i
.ps -6
این فایل با هوشمندانه‌ترین برنامه‌ی حروفچینی دنیا )نیتراف( تولید شده است.
.bp 1
.nr fa.pg 1
.SH "حرف‌های وارونه
.EQ
delim $$
.EN
دو حرف وارونه هستند اگر یکی از آنها کوچک و دیگری بزرگ باشد.  برای مثال،
حروف \*[eq a] و \*[eq A] یا حروف \*[eq D] و \*[eq d] وارونه
هستند.  دو رشته وارونه هستند اگر حروف متناظر آنها وارونه
باشند.  برای نمونه، رشته‌ی \*[eq deFg] نسبت به \*[eq DEfG]
وارونه است اما نسبت به \*[eq DEFG] وارونه نیست.
در این مسئله با گرفتن یک رشته‌ی بلند، باید دو زیر رشته از آن
را بیابید که نسبت به هم وارونه باشند و طول آنها حداکثر باشد.
.PP
فایل ورودی یک خط دارد که رشته‌ی ورودی در آن نوشته شده است )اندازه‌ی
رشته‌ی ورودی حداکثر بیست هزار بایت است(.  خروجی باید شامل دو
عدد باشد که اندیس شروع بزرگ‌ترین زیر رشته‌های وارونه را در
رشته‌ی ورودی نشان می‌دهد.  در نمونه‌ی زیر، طول بزرگ‌ترین زیر رشته‌های
وارونه چهار است؛ رشته‌ی \*[eq bCDA] و رشته‌ی \*[eq Bcda] که
اندیس شروع آنها \*[num 1] و \*[num 9] است.
.iobeg
.ft CB
abCDABCdaBcda
.iocut
1 9
.ioend
