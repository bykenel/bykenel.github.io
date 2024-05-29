-- [LISTA 7]
USE basevendasv2;

-- 1) Implementar integridade referencial em todas as tabelas da basevendas onde houver necessidade.
-- bairro (cidade_id)
ALTER TABLE bairro
ADD CONSTRAINT fk_bairro__cidade_id FOREIGN KEY (cidade_id) REFERENCES cidade (id) ON DELETE RESTRICT ON UPDATE CASCADE;

-- fornecedor (cidade_id)
ALTER TABLE fornecedor
ADD CONSTRAINT fk_fornecedor__cidade_id FOREIGN KEY (cidade_id) REFERENCES cidade (id) ON DELETE RESTRICT ON UPDATE CASCADE;

-- cidade (uf_id)
ALTER TABLE cidade
ADD CONSTRAINT fk_cidade__uf_id FOREIGN KEY (uf_id) REFERENCES uf (id) ON DELETE RESTRICT ON UPDATE CASCADE;

-- venda (cliente_id)
ALTER TABLE venda
ADD CONSTRAINT fk_venda__cliente_id FOREIGN KEY (cliente_id) REFERENCES cliente (id) ON DELETE RESTRICT ON UPDATE CASCADE;

-- cliente (bairro_id, vendedor_id)
ALTER TABLE cliente
ADD CONSTRAINT fk_cliente__bairro_id FOREIGN KEY (bairro_id) REFERENCES bairro (id) ON DELETE RESTRICT ON UPDATE CASCADE,
ADD CONSTRAINT fk_cliente__vendedor_id FOREIGN KEY (vendedor_id) REFERENCES vendedor (id) ON DELETE RESTRICT ON UPDATE CASCADE;

-- lote (produto_id)
DELETE FROM lote
WHERE
    produto_id NOT IN(
        SELECT id
        FROM produto
    )
ALTER TABLE lote
ADD CONSTRAINT fk_lote__produto_id FOREIGN KEY (produto_id) REFERENCES produto (id) ON DELETE RESTRICT ON UPDATE CASCADE;

-- produto (fornecedor_id, tipo_produto_id)
DELETE FROM produto
WHERE
    fornecedor_id NOT IN(
        SELECT id
        FROM fornecedor
    )
ALTER TABLE produto
ADD CONSTRAINT fk_produto__fornecedor_id FOREIGN KEY (fornecedor_id) REFERENCES fornecedor (id) ON DELETE RESTRICT ON UPDATE CASCADE,
ADD CONSTRAINT fk_produto__tipo_produto_id FOREIGN KEY (tipo_produto_id) REFERENCES tipo_produto (id) ON DELETE RESTRICT ON UPDATE CASCADE;

-- produto_vendido (produto_id, venda_id)
ALTER TABLE produto_vendido
ADD CONSTRAINT fk_produto_vendido__produto_id FOREIGN KEY (produto_id) REFERENCES produto (id) ON DELETE RESTRICT ON UPDATE CASCADE,
ADD CONSTRAINT fk_produto_vendido__venda_id FOREIGN KEY (venda_id) REFERENCES venda (id) ON DELETE RESTRICT ON UPDATE CASCADE;