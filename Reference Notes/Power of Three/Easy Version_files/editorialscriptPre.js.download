// The width of the page is a frequent issue. Adding an explicit width to wiki div allows relative
// widths to work when inside.
function GetWidth()
{
      var x = 0;
      if (self.innerHeight) {
              x = self.innerWidth;
      } else if (document.documentElement && document.documentElement.clientHeight) {
              x = document.documentElement.clientWidth;
      } else if (document.body) {
              x = document.body.clientWidth;
      }
      return x;
}
function fixWikiPageWidth() {
    var elems = document.getElementsByTagName('div'), i;
    var f = 0;
    for (i in elems) {
        if((' ' + elems[i].className + ' ').indexOf(' wiki-content ')  > -1) {
            f = 1;
            elems[i].style.maxWidth = (GetWidth() - 248) + 'px';
        }
    }
}
fixWikiPageWidth();


// Some people edit editorials without reading the guidelines. Which then causes
// the rich editor mode to destroy the formatting of our HTML editorial.
// So I add a warning that is displayed only when editing the editorial. 
// The next line makes the warning invisible under normal circumstances:
var temDiv = document.getElementById("richtextwarning");
temDiv.style.display = 'none';
temDiv.style.visibility = 'hidden';
temDiv.style.position = 'absolute';

var disabled = new Array();
var oneDisabled = false;
for (i = 0; i < editorialTabs.length; i++) {
    if (editorialTabs[i][0] == '*' ) {
        oneDisabled = true;
        editorialTabs[i] = editorialTabs[i].substring(1);
        disabled[editorialTabs[i]] = true;
    } else {
        disabled[editorialTabs[i]] = false;
    }
}

if (oneDisabled && (typeof EditorialAccess === 'undefined') ) {
    var editA = document.getElementById("editPageLink");
    if (editA != null) {
        editA.style.display = 'none';
        editA.style.visibility = 'hidden';
        editA.style.position = 'absolute';
    }
    
}

// The following divides the editorial in one tab per problem:
didTab = false;
function doTab(s) {
    //hide all
    didIt = 0;
    for (i = 0; i < editorialTabs.length; i++) {
        var theDiv = document.getElementById(editorialTabs[i]);
        if (editorialTabs[i] == s) {
            didTab = true;
            didIt = 1;
            theDiv.style.position = 'static';
            theDiv.style.display = 'block';
            theDiv.style.visibility = 'visible';
        } else {
            theDiv.style.display = 'none';
            theDiv.style.visibility = 'hidden';
            theDiv.style.position = 'absolute';
            
        }
    }
    if (didIt == 0) {
        var i = 0;
        while ( i < editorialTabs.length && disabled[editorialTabs[i]] ) {
            i++;
        }
        if (i < editorialTabs.length) {
            didTab = true;
            doTab(editorialTabs[i]);
        }
    }
}

function DoDefaultTab() {
    if (! didTab) {
        doTab(window.location.hash.substring(1));
    }
}

//Hide all tabs:
for (i = 0; i < editorialTabs.length; i++) {
    var s = editorialTabs[i];
    temDiv = document.getElementById(s);
    temDiv.style.display = 'none';
    temDiv.style.visibility = 'hidden';
    temDiv.style.position = 'absolute';
}

var all = document.getElementsByTagName("a");

for (i=0, max=all.length; i < max; i++) {
    var el = all[i];
    var s = el.getAttribute("href");
    var j = s.length;
    while (j > 0 && s[j-1] != '#') {
        j--;
    }
    var tabLinks = document.getElementById("tabLinks");
    if (j > 0) {
        s = s.substr(j);
        if (disabled[s]) {
            el.style.visibility = 'hidden';
            el.style.position = 'absolute';
            var text = document.createTextNode('*'+s);
            el.parentNode.insertBefore(text, el);
        } else {
            for (var k = 0; k < editorialTabs.length; k++) {
                if (editorialTabs[k] == s) {
                    el.onclick = function(S) { return function() { 
                        doTab(S); 
                        tabLinks.scrollIntoView(true);
                        return false; 
                    }; }(s);
                }
            }
        }
    }
}

// SVG images are better for the graphics used in editorials. I already use
// a vector graphics program to code them in the first place. SVG format allows
// users to zoom in/out the images without getting blurry results.

// Unfortunatlely SVG support is not widespread in browsers even though it is
// an HTML5 standard. A fallback is needed. So images with name that ends
// with "svg.png" are made to use ".svg" instead if SVG is enabled. In order to
// find if SVG is enabled, we use the Modernizr script.
if (Modernizr.svg) {
    var allimg = document.getElementsByTagName("img");
    for (i=0, max=allimg.length; i < max; i++) {
        var s = allimg[i].src;
        if ( (s.length > 7) && (s.substring(s.length - 7) == 'svg.png' ) ) {
            allimg[i].src = allimg[i].src.substring(0, s.length - 7) + '.svg'; 
        }
    }
}

