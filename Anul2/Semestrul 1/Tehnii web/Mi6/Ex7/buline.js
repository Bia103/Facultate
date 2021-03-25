Disc.MIN_RAZA = 20;
Disc.MAX_RAZA = 100;
class Disc {
  constructor(_x = 0, _y = 0, _raza = 50, _culoare = "black") {
    this.x = _x;
	this.y = _y;
	this.raza = _raza;
	this.culoare = _culoare;
  }
  Culoare() {
    return this.culoare;
  }
  setRaza(_r) {
	 this.raza = _r;
  }
  getRaza(){
	  return this.raza;
  }
  desenDisc(){
		var div = document.createElement("div");
		div.style.width = this.raza;
		div.style.height = this.raza;
		document.body.appendChild(div);
		div.style.position = "absolute";
		div.style.left = this.x+'px';
		div.style.top = this.y+'px';
		div.style.borderRadius = 50 + 'px';
		div.style.color = this.color;
		document.body.appendChild(div);
		this.ok = 1;
  }
  testDesen(){
	  if(this.ok)
		  return 1;
	  else return 0;
  }
}

window.onload=function(){
	var c = new Disc(20,25,50,"black");
	c.desenDisc();
}