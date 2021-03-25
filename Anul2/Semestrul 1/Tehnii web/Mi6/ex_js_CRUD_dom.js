function randInt(a,b){
	return Math.trunc(a+(b-a)*Math.random());
}


var vPrenume=["Costica", "Gigel", "Dorel", "Maricica", "Dorica", "Gigileana", "Crinisoara", "Zoe", "Gogu", "Bob"];
var vPrefixeNume=["Bubul", "Bondar", "Dudul", "Gogul", "Zumzul"];
var vSufixeNume=["ache", "escu", "esteanu","eanu", "eschi"];
var grupe=["A", "B", "C", "D"];


function noteRandom(){
	var nrNote=randInt(1,5);
	var note=[];
	for(let i=0;i<nrNote;i++)
	{
		note.push(randInt(1,11));
	}
	return note;
}


function elevRandom(){
	return{
		prenume: vPrenume[randInt(0, vPrenume.length)],
		nume: vPrefixeNume[randInt(0, vPrefixeNume.length)]+vSufixeNume[randInt(0, vSufixeNume.length)],
		grupa: grupe[randInt(0, grupe.length)],
		note: noteRandom()
	};
}
function genereazaElevi(n){
	var elevi=[];
	for(let i=0;i<n;i++){
		elevi.push(elevRandom());
	}
	console.log(elevi);
	return elevi;
}

function creeazaRand(tipCelula, vector){
	var tr=document.createElement("tr"); //TO DO sa se creeze un rand
	for(x of vector){
		var celula=document.createElement(tipCelula);
		celula.innerHTML=x;
		
 //TO DO continutul celulei trebuie sa fie valuarea din vector
		tr.appendChild(celula);// TO DO adaugati celula in rand
	}
	return tr;
}

function creeazaTabel(elevi){
	if(!elevi || elevi.length==0) return;
	
	var tabel=document.createElement("table");
	tabel.id="tab";
	var thead=document.createElement("thead");// TO DO - creare thead
	 // TO DO - adugare thead in tabel
	tabel.appendChild(thead);
	var rand=creeazaRand("th",Object.keys(elevi[0]));   //orice elev existent
	console.log("Proprietati:");
	console.log(Object.keys(elevi[0]));
	thead.appendChild(rand);
		
	
	var tbody=document.createElement("tbody");
	tabel.appendChild(tbody);
	for(let elev of elevi){ //TO DO vrem ca variabila elev sa aiba pe rand ca valoare fiecare element din elevi
		rand=creeazaRand("td",Object.values(elev));
		console.log("Valori:");console.log(Object.values(elev));
		tbody.appendChild(rand);
		rand.classList.add(elev.grupa);//clasa sa fie egala cu clasa elevului
		
		rand.onclick=function(e){
			//TO DO corectati
			
if(e.ctrlKey){
this.remove();
afisLog("Am sters un elev");
		}else 
this.classList.toggle("selectat");   // toggle sterge daca exista, adauga daca nu exista	
		}
	}
	return tabel;
}

contor=0;
function afisLog(textLog){
	var info=document.getElementById("info");
	var p=document.createElement("p");
p.innerHTML="["+ new Date() +"]" + textLog;
	info.appendChild(p);
	contor++;
	info.title=contor;
}

function deselectare()
{
	var tabel=document.getElementById("tab");
		var tbody=tabel.getElementsByTagName("tbody")[0];
		var v=tbody.getElementsByClassName("selectat");
		
		while(v.length>0)
		{
			v[0].classList.remove("selectat");
		}
}



window.onload=function(){
	var v_elevi=genereazaElevi(10);
	document.getElementById("container_tabel").appendChild(creeazaTabel(v_elevi));
	document.getElementById("add_inceput").onclick=function()
	{
		var tabel=document.getElementById("tab");
		var tbody=tabel.getElementsByTagName("tbody")[0];
		var rand=creeazaRand("td", Object.values(elevRandom()));   //object.values e predefinit si returneaza valorile atributelor
		tbody.insertBefore(rand, tbody.firstChild);  //inseram in fata primului rand
	}
	
	document.getElementById("add_sfarsit").onclick=function()
	{
		var tabel=document.getElementById("tab");
		var tbody=tabel.getElementsByTagName("tbody")[0];
		var rand=creeazaRand("td", Object.values(elevRandom()));   
		tbody.appendChild(rand);  //inseram un rand la sfarsit
	}
	
	document.getElementById("deselectare").onclick=deselectare;   //elementele dupa Id-ul dat primesc ca valoare functia insasi (devin de tip functie)
	
	document.getElementById("sterge").onclick=function()
{
var tabel=document.getElementById("tab");

var tbody=tabel.getElementsByTagName("tbody")[0];

do{
var rasp=prompt("Clasa?");
}while(grupe.indexOf(rasp)==-1);

deselectare();

var elevi=tabel.querySelectorAll("."+rasp);

for(el of elevi)
{
el.classList.add("selectat");
}

var conf=confirm("Șterge?");

if(conf)
{
for(el of elevi) el.remove();
}

}

document.getElementById("sorteaza_nume").onclick=function()
{
var tabel=document.getElementById("tab");

var tbody=tabel.getElementsByTagName("tbody")[0];

v_tr=Array.prototype.slice.call(tbody.children);    

v_tr.sort(function(a, b){     //negativ ->a<b
	
	return (a.children[1].innerHTML+a.children[0].innerHTML).localeCompare(b.children[1].innerHTML+b.children[0].innerHTML);
	
})

for(tr of v_tr){
	tbody.appendChild(tr);


}
}
document.getElementById("sorteaza_medie").onclick=function()
{
var tabel=document.getElementById("tab");

var tbody=tabel.getElementsByTagName("tbody")[0];

v_tr=Array.prototype.slice.call(tbody.children);    

v_tr.sort(function(a, b){     //negativ ->a<b
	
	note_a=a.children[3].innerHTML.split(",");
	sum_a = note_a.reduce(function myFunc(total, num) {
  return parseInt(total) + parseInt(num);
  })
  media_a = sum_a/note_a.length;
  
  note_b=b.children[3].innerHTML.split(",");
	sum_b = note_b.reduce(function myFunc(total, num) {
  return parseInt(total) + parseInt(num);
  })
  media_b = sum_b/note_b.length;
  return media_a-media_b;

	
})

for(tr of v_tr){
	tbody.appendChild(tr);


}
}	
document.getElementById("select_elevi").onclick=function()
{
var tabel=document.getElementById("tab");

var tbody=tabel.getElementsByTagName("tbody")[0];

v_tr=Array.prototype.slice.call(tbody.children);    

v_nou = v_tr.filter(function(a){
	note_a=a.children[3].innerHTML.split(",");
	sum_a = note_a.reduce(function myFunc(total, num) {
  return parseInt(total) + parseInt(num);
  })
  media_a = sum_a/note_a.length;
  return media_a>=5;
	
})
deselectare();
for(tr of v_nou){
	tr.classList.add("selectat");


}
document.getElementById("gaseste_elev").onclick=function()
{
	var tabel=document.getElementById("tab");
	var tbody=tabel.getElementsByTagName("tbody")[0];
	v_tr=Array.prototype.slice.call(tbody.children); 
	prenume=prompt("Prenume=?");
	v_tr.findIndex(function(a){
		return a.children[0].innerHTML == prenume;
	})
	if (ind == -1)
		alert("NU");
	else 
		alert(ind);

}
document.getElementById("inverseaza").onclick=function()
{
	var tabel=document.getElementById("tab");
	var tbody=tabel.getElementsByTagName("tbody")[0];
	v_tr=Array.prototype.slice.call(tbody.children); 
	for(i=v_tr.length-1;i>=0;i--)
		tbody.appendChild(v_tr[i]);

}
document.getElementById("goleste_tabel").onclick=function()
{
	var tabel=document.getElementById("tab");
	var tbody=tabel.getElementsByTagName("tbody")[0];
	v_tr=Array.prototype.slice.call(tbody.children); 
	tbody.innerHTML="";

}

}

}

window.onkeypress=function(e){
	var cod = e.charCode?e.charCode:e.keyCode;
	var tasta = String.fromCharCode(cod).toUpperCase;		//cod ascii to litera
	// cod_a = "a".charCodeAt(0);
	if grupe.indexOf(tasta)==-1
		return;
	var tr_s = tbody.querySelectorAll(".selectat");
	for(tr of tr_s){
		for(gr of grupe){
		tr.classList.remove(gr);}}
	tr.classList.remove("nu mai stiu ce");
	tr.children(2).innerHTML=tasta;
}










