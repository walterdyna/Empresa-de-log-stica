async function exibirProdutos() {
    try {
        const response = await fetch('/cgi-bin/estoque_api.cgi');
        const data = await response.text();
        document.getElementById('output').innerText = data;
    } catch (error) {
        console.error('Erro ao exibir produtos:', error);
    }
}

function adicionarProduto() {
    const codigo = prompt("Digite o código do produto:");
    const nome = prompt("Digite o nome do produto:");
    const quantidade = prompt("Digite a quantidade:");
    const valor = prompt("Digite o valor unitário:");

    fetch('/cgi-bin/estoque_api.cgi', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded'
        },
        body: `codigo=${codigo}&nome=${nome}&quantidade=${quantidade}&valor=${valor}`
    })
    .then(response => response.text())
    .then(data => {
        document.getElementById('output').innerText = data;
    })
    .catch(error => console.error('Erro ao adicionar produto:', error));
}
