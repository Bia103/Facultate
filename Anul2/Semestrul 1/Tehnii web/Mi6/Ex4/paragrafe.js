window.onload=function(){

	document.getElementById("albastreste").onclick = albastreste; //TO DO

}
// f() se comporta ca o functie
// f e referinta
function albastreste(){
	pgfs=document.querySelectorAll("p");
	//alert(stil.color);
	//alert(stil.color);
	for(pg of pgfs){
		var stil = getComputedStyle(pg);	// trebuie tratat ca un read only(getComputedStyle)
		if(stil.color == "rgb(255,0,0)")
			pg.style.color = "blue";
	}
	//de observat si apoi de comentat
	//alert(pgfs[0].style.color)		// scrie NULL
	//pgfs[0].style.color="blue"
	//alert(pgfs[0].style.color)		// scrie blue
}