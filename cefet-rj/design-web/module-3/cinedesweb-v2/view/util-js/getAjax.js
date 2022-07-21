function getAjax (method, url, reqSuccess, reqError, data = null) {
    let xhr = new XMLHttpRequest();
    xhr.open(method, url); 
    xhr.setRequestHeader('Content-type', 'Application/json');
    xhr.send(JSON.stringify(data));

    xhr.onreadystatechange = function() {
        if(xhr.readyState === 4) {
            if(!(xhr.status === 200 || xhr.status === 304)) {
                reqError('Erro do cliente '+xhr.statusText);
            }

            if(xhr.status === 200 || xhr.status === 304) {
                let response = JSON.parse(xhr.responseText);
                console.log(response);
                if (response.error === false) {
                    reqSuccess(response);
                } else {
                    reqError(response.errorMsg);
                }
            }
        }
    }
}