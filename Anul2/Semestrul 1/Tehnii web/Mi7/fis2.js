window.onmousedown=function(e){
	var div= document.createElement("div");
	document.body.appendChild(div);
	div.style.border="1px solid black";
	div.style.position="absolute";
	div.style.top=div.style.left="0" //pot sa nu pun unit masura pt ca e 0
	if(e.shiftKey){
		div.style.background="red"
	}
	else
		div.style.background="blue"
	div.style.width=e.clientX+"px";
	div.style.height=e.clientY+"px";
	div.id="dr";
}

window.onmouseup=function(e){
	var div= document.getElementById("dr")
	div.remove()
}

