//QUESTÃO 1
function sum() {
    var nu1 = window.document.getElementById('num1');
    var nu2 = window.document.getElementById('num2');
    var res = window.document.getElementById('res');
    var n1 = Number(nu1.value);
    var n2 = Number(nu2.value);
    var s = n1 + n2;
    res.innerHTML = `A soma é igual a ${s}`;
}

//QUESTÃO 2
function comparison() {
    var nu1 = window.document.getElementById('num1');
    var nu2 = window.document.getElementById('num2');
    var res = window.document.getElementById('res');
    var n1 = Number(nu1.value);
    var n2 = Number(nu2.value);
    if (n1 > n2) {
        res.innerHTML = `${n1} é maior do que ${n2}`;
    } else {
            if (n2 > n1) {
                res.innerHTML = `${n1} é menor do que ${n2}`; 
            } else {
                res.innerHTML = `Os números são iguais`; 
            }
    }
}

//QUESTÃO 3
function prime() {
    var nu1 = window.document.getElementById('num1');
    var res = window.document.getElementById('res');
    var n1 = Number(nu1.value);
    var div = 0;
    for (var i = 1; i <= n1; i++) {
        if (n1 % i == 0)
        div++;
    }
    if (div == 2) {
        res.innerHTML= `${n1} é primo`;
    } else {
        res.innerHTML= `${n1} não é primo`;
    }
}

//QUESTÃO 4
function hypot() {
    var cat1 = window.document.getElementById('num1');
    var cat2 = window.document.getElementById('num2');
    var res = window.document.getElementById('res');
    var c1 = Number(cat1.value);
    var c2 = Number(cat2.value);
    h = hypot.value = Math.hypot(c1, c2).toFixed(2);
    res.innerHTML = `A hipotenusa é igual a ${h}`;
}

//QUESTÃO 5
function readjust() {
    var sal = window.document.getElementById('num1');
    var por = window.document.getElementById('num2');
    var res = window.document.getElementById('res');
    var s = Number(sal.value);
    var p = Number(por.value);
    p = p / 100;
    var ns = (s * p) + s;
    res.innerHTML = `O novo salário é igual a ${ns}`;
}

//QUESTÃO 6
function converter() {
    var nu1 = window.document.getElementById('num1');
    var res = window.document.getElementById('res');
    var f = Number(nu1.value);
    var c = (f - 32) * 5 / 9;
    res.innerHTML = `A temperatura ${f} em F° equivale a ${c} em C°`;
}

//QUESTÃO 7
function media() {
    var nu1 = window.document.getElementById('num1');
    var nu2 = window.document.getElementById('num2');
    var nu3 = window.document.getElementById('num3');
    var res = window.document.getElementById('res');
    var n1 = Number(nu1.value);
    var n2 = Number(nu2.value);
    var n3 = Number(nu3.value);
    var mf = (n1 * 2 + n2 * 3 + n3 * 5) / 10;
    res.innerHTML = `A média final é igual a ${mf}`;
}