# Monitor de gás com ESP32 e sensor MQ-2

Projeto educacional que lê o sinal analógico de um módulo MQ-2, mostra uma classificação simples no LCD 16x2 e aciona um buzzer quando a leitura ultrapassa o limite definido no código.

> Este protótipo não é um detector certificado e não deve ser usado para segurança contra incêndio, vazamento ou exposição a gases. Os limites abaixo são valores brutos do ADC usados no programa, não concentração em ppm.

## Componentes e ligações

| Componente | ESP32 |
|---|---|
| Saída analógica do módulo MQ-2 | GPIO 34 |
| Buzzer | GPIO 5 |
| LCD 16x2 I2C | Endereço 0x27 |

Confira a pinagem e a tensão de saída do seu módulo antes de conectá-lo ao ESP32. O GPIO do ESP32 não deve receber tensão acima do limite permitido pela placa.

## Funcionamento do código

O sketch usa os pinos SDA e SCL padrão da placa selecionada na Arduino IDE. `0x27` é o endereço do LCD no barramento I²C.

O ESP32 lê o GPIO 34 e compara o valor com faixas fixas. O LCD é atualizado a cada segundo e o valor bruto também aparece no Monitor Serial a 9600 baud.

| Leitura analógica | LCD | Buzzer |
|---|---|---|
| Acima de 2700 | PERIGO! | Ligado |
| Acima de 2200 até 2700 | RUIM | Desligado |
| Acima de 1500 até 2200 | BOM | Desligado |
| 1500 ou menos | MUITO BOM | Desligado |

Essas faixas são configurações do exemplo e podem variar conforme o sensor, o módulo, a alimentação e as condições do ambiente. O código não converte a leitura para ppm nem faz calibração do sensor.

## Bibliotecas

Instale a biblioteca `LiquidCrystal_I2C` e selecione uma placa ESP32 compatível na Arduino IDE.

## Executar

1. Abra [`SensorDeGas.ino`](SensorDeGas.ino) na Arduino IDE.
2. Confira as ligações e o endereço I2C do LCD.
3. Selecione a placa ESP32 e a porta correta.
4. Envie o programa e abra o Monitor Serial em 9600 baud.

## Possíveis melhorias

- Calibrar o sensor e registrar as condições do teste.
- Ajustar os limites com base em medições documentadas.
- Evitar limpar o LCD a cada ciclo para reduzir cintilação.
- Adicionar registro das leituras ao longo do tempo.
