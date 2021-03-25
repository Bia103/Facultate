window.onload=function(){
  var btn = document.createElement("BUTTON");
  btn.innerHTML = "inversare DOM";
  document.body.appendChild(btn);
  var btn2 = document.createElement("BUTTON");
  btn2.innerHTML = "reversed";
  document.body.appendChild(btn2);
  btn.onclick=function()
	{
		var x, i;
		x = document.querySelectorAll("li");
		
		 for (i = x.length - 1; i >= 0; i--) {
			document.body.appendChild(x[i]);
			}
		document.body.appendChild(btn);
		document.body.appendChild(btn2);
		//var y = document.getElementById("lista");
		//y.start = "0";
	}
btn2.onclick=function()
	{
		document.getElementById("lista").reversed = true;
	}
}

