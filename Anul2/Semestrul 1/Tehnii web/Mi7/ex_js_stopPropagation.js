function f(elem){
	alert(elem.tagName)
    }

window.onload=function(){
    
    albastru=true
    
    document.getElementById("dv").onclick=function(ev){
   	 f(this)
   	 if(ev.target==ev.currentTarget){
		this.style.background= albastru ? "red" : "blue"
		albastru= ! albastru
}

    }
    
    document.getElementById("btn").onclick=function(ev){
   	 f(this)   	 
    }
    
    document.getElementById("btn2").onclick=function(ev){
	ev.stopPropagation()
   	 f(this)   	 
    }    
}
