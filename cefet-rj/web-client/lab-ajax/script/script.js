const http = new EasyAjax
http.get('https://rafaelescalfoni.github.io/desenv_web/filmes.json', function(status, response) {
    if(status) {
        console.log(status);
    } else {
        let aux = '';

        response.forEach(data => {
            const showRating = document.createElement("div");
            let castAux = '<h2>Elenco</h2>';
            let generosAux = '<h2>Gênero</h2>';
            let similarAux = '<h2>Similares</h2>';
            let opinioesAux = '';

            function eachForLoops() 
                {data.elenco.forEach(cast => {
                    const li = document.createElement("li");
                    li.appendChild(document.createTextNode(cast));
                    castAux += li.outerHTML;
                });

                data.generos.forEach(genre => {
                    const li = document.createElement("li");
                    li.appendChild(document.createTextNode(genre));
                    generosAux += li.outerHTML;
                });

                data.titulosSemelhantes.forEach((similar, k) => {
                    response.forEach(test => {
                        if(test.id == similar) {
                            const li = document.createElement("li");
                            li.appendChild(document.createTextNode(test.titulo));
                            similarAux += li.outerHTML;
                        }
                    });
                });
            } 
            
            eachForLoops();

            aux += `<div class="card">
                    <div class="movie">
                    <div class="imageContainer">
                    <img src=${data.figura}>
                    </div>
                    
                    <div class="description">
                    <h1>${data.titulo}</h1>
                    ${showRating.outerHTML}
                    <h4>${data.resumo}</h4>
                    <hr> 
                
                    <div class="showInfo">
                    <div class="cast">
                    <ul>${castAux}</ul>
                    </div>

                    <div clas="similar">
                    <ul>${similarAux}</ul>
                    </div>
                    
                    <div class ="genrers">
                    <ul>${generosAux}</ul>
                    </div>
                    </div>
                    </div>
                    </div>
                    </div>`; 

                document.querySelector('.movies').innerHTML = aux;
            });
      }
});