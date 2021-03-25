window.onload=function(){
	var lst= document.getElementById("lista");
	for (li of lst.children){
		li.onclick=function(){
			this.style.color="green";
			li_p=this;
			while(li_p.previousElementSibling){
				li_p=li_p.previousElementSibling
				li_p.style.color="red";
			}
			li_p=this;
			while(li_p.nextElementSibling){
				li_p=li_p.nextElementSibling
				li_p.style.color="blue";
			}
		}
	}
}



























