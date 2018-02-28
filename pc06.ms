.\" PSTITLE: NIT Wednesday Programming Problem \- PC06
.so pc__.ms
.ps.info "NIT Wednesday Programming Problem - PC06" "Ali Gholami Rudi"
.nr fa.pg 0
.ds fa.cl "#74b573
.blm PP
.TL "چهارشنبه‌ی ششم\&" "مسئله‌ی برنامه‌نویسی \m[#8f4]چهارشنبه\m[]\&" "می‌خواهیم بهترین باشیم..."
.sp 1
.LP
ماه‌ها منتظر بودیم و نقشه می‌کشیدیم.  هر روز را با این انگیزه
آغاز می‌کردیم که شاید آرزوی ما به حقیقت پیوسته باشد.
ماه‌هایی پر از انتظار، دلهره و هیجان.
و در نهایت پس از حدود یک سال،
این انتظار خاتمه می‌یابد و چهارشنبه‌ها همزمان با طبیعت
دوباره جان می‌گیرد.
دوباره علاقمندان با اشتیاق به سرور پنج‌شنبه‌های سخت
چشم می‌دوزند تا ببینند بهترین‌ها چه کسانی هستند.
.sp |6.5i
.nr VS -6
.tblbeg 4i 0
.	tblbox 1 1 1
.	tblmac fa.tblfc fa.tblfc
.	tblrow "\f(FXحفاری‌ها\fP" "\f(FXعنوان مسئله\fP"
.	tblrow "\*[en pc06]" "\f(FXشناسه‌ی مسئله\fP"
.	tblrow "\*[num 4] از \*[num 9]" "\f(FXسختی مسئله\fP"
.	tblrow "ساعت \*[num 16]    \*[num 1396/12/16]" "\f(FXزمان شروع\fP"
.	tblrow "ساعت \*[num 16]    \*[num 1397/\01/\08]" "\f(FXزمان پایان\fP"
.tblend
.nr VS +6

.LP
.sp |9.5i
.ps -6
این فایل با نیتراف )هوشمندانه‌ترین برنامه‌ی حروفچینی دنیا( تولید شده است.
.bp 1
.nr fa.pg 1
.SH "حفاری‌ها
در یک سال گذشته که نگارش این نشریه متوقف شده بود،
شهر نانل با شهردار جدیدش همواره در حال رشد بوده
است؛ آمار منتشر شده توسط شهردار نانل این رشد بی‌سابقه
را به خوبی اثبات می‌کند.
در واقع، یکی از مهم‌ترین دست‌آوردهای شهردار، استخراج
آمارهای خوب از کارهای انجام شده است.
اما شهردار یکی از مهم‌ترین چالش‌های پیش رویش را هنوز
نتوانسته است حل کند.
مسئله این است که به نظر شهردار یکی از متغیرهایی که
رشد یک شهر را نشان می‌دهد تعداد حفاری‌هایی است که
به صورت متوسط در واحد زمان در خیابان‌های آن شهر انجام می‌شود و
او فکر می‌کند از این دید نانل یکی از پیشرفته‌ترین شهرهای جهان باشد.
اما متأسفانه به علت وسعت عملیات عمرانی شهرداری،
آمار دقیقی در اختیار وی نیست.
پس از ساعت‌های جلسه با کارشناسان مختلف برای حل این مشکل )در
دسترس نبودن آمار( در نهایت شهردار با به کارگیری گروهی از
متخصصان تحلیل عکس‌های ماهواره‌ای، مختصات حفاری‌های انجام شده
در منطقه‌ی شهر نانل را بدست آورده است.
اما متأسفانه همه‌ی این حفاری‌ها در محدوده‌ی سیاسی شهر نانل نیستند.
به شهردار کمک کنید تا تعداد حفاری‌های داخل نانل را محاسبه کند.
شهر نانل به شکل یک چند ضلعی محدب است؛ شهردار مختصات رأس‌های این
چند ضلعی را در اختیار شما قرار می‌دهد.
.bp
.SH "ورودی و خروجی
ورودی با دو عدد شروع می‌شود.  عدد اول تعداد رأس‌های چند ضلعی را نشان
می‌دهد )حداکثر صد هزار( و عدد دوم تعداد نقطه‌های پرسش را مشخص
می‌کند )حداکثر دویست هزار(.
سپس، مختصات رأس‌های چند ضلعی داده می‌شوند )به ترتیب در جهت یا خلاف جهت
عقربه‌های ساعت( و سپس از آن مختصات نقطه‌های
ورودی مشخص می‌گردند.  مؤلفه‌های هر یک از این نقطه‌ها بین مثبت و منفی
صد هزار هستند.
خروجی به ازای هر یک از نقطه‌های ورودی شامل یک عدد است
که تعیین می‌کند نقطه‌ی متناظر آن در داخل یا خارج از شهر
است.  اگر این عدد یک باشد یعنی نقطه‌ی ورودی داخل و
اگر صفر باشد یعنی نقطه‌ی ورودی متناظر آن خارج از شهر است.
نقطه‌های روی مرز خارج از شهر محسوب می‌شوند.

یک نمونه‌ی ورودی در ادامه نمایش داده می‌شود.  در این نمونه،
چند ضلعی پنج رأس دارد و چهار نقطه به عنوان پرسش داده می‌شوند.
.iobeg
5 4
1 2
4 1
3 0
0 0
0 1
2 2
1 1
4 0
3 1
.iocut
0
1
0
1
.ioend
.LP
شکل زیر، نمونه‌ی قبل را به صورت تصویری نمایش می‌دهد.
نقطه‌های پرسش با مربع نشان داده شده‌اند )عدد کنار هر
مربع، ترتیب آن نقطه را در ورودی مشخص می‌کند(.
.PS 2.5i
circlerad = .03
boxwid = .05
boxht = .05
.	vs \n(PS+6
.	cl #833
P1:	circle fill -1 at (1, 2)
P2:	circle fill -1 at (4, 1)
P3:	circle fill -1 at (3, 0)
P4:	circle fill -1 at (0, 0)
P5:	circle fill -1 at (0, 1)
.	cl #338
.	ps +4
	line from P1 to P2 chop
	line from P2 to P3 chop
	line from P3 to P4 chop
	line from P4 to P5 chop
	line from P5 to P1 chop

.	ps \n(PS-2
.	cl #444
	box fill -1 at (2, 2) "1" below
	box fill -1 at (1, 1) "2" below
	box fill -1 at (4, 0) "3" below
	box fill -1 at (3, 1) "4" below
.PE
.LP
.bp
.SH "فرستادن جواب‌ها
در \*[urlfa http://nit.rudi.ir/ctsubmit.pdf "این مستند"] گام‌های
لازم برای فرستادن جواب، دیدن نتیجه‌ی ارزیابی و شیوه‌ی انتخاب بهترین
جواب شرح داده شده‌اند.
برای فرستادن جواب از سیستم عامل ویندوز، می‌توانید از
\*[urlfa https://github.com/includeamin/NITCT/raw/master/Release/NITCT.exe "این برنامه"]
که توسط آقای امین جمال نوشته شده است استفاده کنید.
بهترین جواب در این مسئله نمره‌ی اضافه دریافت خواهد کرد.

برنامه‌هایی که فرستاده می‌شوند باید از ورودی استاندارد
ورودی‌های مسئله را بخوانند و خروجی‌ها را به خروجی استاندارد
بفرستند.
هر برنامه، به ازای تعدادی نمونه‌ی ورودی اجرا می‌شود.
در ستون آخر نتایج، به ازای هر نمونه‌ی ورودی یک حرف نمایش داده
می‌شود.  در این ستون حرف \*[en P] به معنی خروجی با شکل مناسب،
حرف \*[en F] به معنی خروجی اشتباه،
حرف \*[en T] به معنی خاتمه نیافتن جواب در زمان مجاز دو ثانیه،
حرف \*[en E] به معنی خطای ترجمه و
حرف \*[en R] به معنی خطای زمان اجرا است.
در صورتی که خروجی با شکل مناسب تولید شده باشد، به جواب امتیازی
برای آن نمونه داده می‌شود.
مجموع امتیازها در نمونه‌های ورودی، در ستون سوم نتایج نمایش
داده می‌شود.  قطعا بهترین جواب، جوابی است که امتیاز بالاتری را
به دست می‌آورد )به نمونه‌های بیشتری به درستی پاسخ داده است(.

دقت کنید که برای فرستادن جواب‌ها با زبان جاوا، برنامه باید
یک کلاس به نام \*[en Main] داشته باشد و در یک \*[en package]
نگرفته باشد.