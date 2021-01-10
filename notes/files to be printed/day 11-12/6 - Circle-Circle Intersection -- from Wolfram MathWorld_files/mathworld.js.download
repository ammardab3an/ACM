function togglelinktrail (id) {
el = document.getElementById (id);
cls = el.className;
action = 0;
if (cls.lastIndexOf ('_Co') == cls.length - 3) {
openlinktrail (el);
}
else if (cls.lastIndexOf ('_Ex') == cls.length - 3) {
closelinktrail (el);
}
}

function openlinktrail (el, func, userdata) {
var cls = el.className;
 var clsPre = cls.substring (0, cls.length - 3);
 if (clsPre == 'ES') {
 var el_cnt;
 for (el_cnt = el.firstChild; el_cnt; el_cnt = el_cnt.nextSibling) {
 if (el_cnt.nodeType == 1 && el_cnt.className == clsPre) {
 break;
 }
 }
 if (func) {
 func (userdata);
 }
 }
 el.className = clsPre + '_Ex';
}

function closelinktrail (el) {
 var cls = el.className;
 var clsPre = cls.substring (0, cls.length - 3);
 el.className = clsPre + '_Co';
}

window.addEventListener('load', function(){
      var linktext = document.getElementById('try').getElementsByTagName('div')[0].getElementsByTagName('a')[0].text;
      if(typeof linktext != undefined){
      		document.getElementById("i").value = linktext;
      }
    });