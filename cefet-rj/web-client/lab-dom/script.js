//QUESTÃO 1
function sum() {
    let n1 = window.document.getElementById('num1').value;
    let n2 = window.document.getElementById('num2').value;
    let res = window.document.getElementById('res');
    let s = n1 + n2;
    res.innerHTML = `A soma é igual a ${s}`;
}

//QUESTÃO 2
function comparison() {
    let n1 = window.document.getElementById('num1').value;
    let n2 = window.document.getElementById('num2').value;
    let res = window.document.getElementById('res');
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
    let n1 = window.document.getElementById('num1').value;
    let res = window.document.getElementById('res');
    let div = 0;
    for (let i = 1; i <= n1; i++) {
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
    let c1 = window.document.getElementById('num1').value;
    let c2 = window.document.getElementById('num2').value;
    let res = window.document.getElementById('res');
    h = hypot.value = Math.hypot(c1, c2).toFixed(2);
    res.innerHTML = `A hipotenusa é igual a ${h}`;
}

//QUESTÃO 5
function readjust() {
    let s = window.document.getElementById('num1').value;
    let p = window.document.getElementById('num2').value;
    let res = window.document.getElementById('res');
    p = p / 100;
    let ns = (s * p) + s;
    res.innerHTML = `O novo salário é igual a ${ns}`;
}

//QUESTÃO 6
function converter() {
    let f = window.document.getElementById('num1').value;
    let res = window.document.getElementById('res');
    let c = (f - 32) * 5 / 9;
    res.innerHTML = `A temperatura ${f} em F° equivale a ${c} em C°`;
}

//QUESTÃO 7
function media() {
    let n1 = window.document.getElementById('num1').value;
    let n2 = window.document.getElementById('num2').value;
    let n3 = window.document.getElementById('num3').value;
    let res = window.document.getElementById('res');
    let mf = (n1 * 2 + n2 * 3 + n3 * 5) / 10;
    res.innerHTML = `A média final é igual a ${mf}`;
}