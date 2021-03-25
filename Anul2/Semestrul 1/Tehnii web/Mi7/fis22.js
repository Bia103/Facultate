div=null;
window.onkeydown=function(e){
	if(! div){	
		var div= document.createElement("div");
		document.body.appendChild(div);
		div.innerHTML=e.key //tasta apasata
		div.style.fontSize="10px"
	}
	else{
		div.style.fontSize=parseInt(div.style.fontSize)+1+"px"
	}
	
}

window.onkeyup=function(e){
	if(div){
		div.remove()
		div=null
}
}

