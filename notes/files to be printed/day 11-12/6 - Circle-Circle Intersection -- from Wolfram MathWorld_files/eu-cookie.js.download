
/*  Replace relative URL with absolute URL on non-WolframAlpha domains */
if(!(new RegExp("(?:^|;\\s*)" + escape("CookieWarning").replace(/[\-\.\+\*]/g, "\\$&") + "\\s*\\=")).test(document.cookie)){
	 document.cookie = 'CookieWarning=nom; expires=Fri, 3 Aug 2020 20:47:11 UTC; path=/';
	document.write('\x3Cscr'+'ipt src="//www.wolframalpha.com/input/cookietest.jsp" type="text/javascript">\x3C'+'/script>');
}
