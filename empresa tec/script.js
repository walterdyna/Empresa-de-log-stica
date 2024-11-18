function drawLine(from, to) {
    const line = document.createElement('div');
    line.className = 'line';
    
    const fromRect = from.getBoundingClientRect();
    const toRect = to.getBoundingClientRect();
    
    const x1 = fromRect.left + fromRect.width / 2;
    const y1 = fromRect.top + fromRect.height / 2;
    const x2 = toRect.left + toRect.width / 2;
    const y2 = toRect.top + toRect.height / 2;

    const length = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    const angle = Math.atan2(y2 - y1, x2 - x1) * 180 / Math.PI;

    line.style.width = length + 'px';
    line.style.transform = `rotate(${angle}deg)`;
    line.style.left = `${x1}px`;
    line.style.top = `${y1}px`;

    document.querySelector('.container').appendChild(line);
}

// Desenhar linhas de conexão entre os dispositivos
window.onload = function() {
    const router = document.getElementById('router');
    const switch1 = document.getElementById('switch1');
    const switch2 = document.getElementById('switch2');
    const switch3 = document.getElementById('switch3');
    const accessPoint1 = document.getElementById('accessPoint1');
    const accessPoint2 = document.getElementById('accessPoint2');
    const dataCenter = document.getElementById('dataCenter');
    const server1 = document.getElementById('server1');
    const server2 = document.getElementById('server2');
    const devWorkstation1 = document.getElementById('devWorkstation1');
    const devWorkstation2 = document.getElementById('devWorkstation2');
    const designWorkstation = document.getElementById('designWorkstation');
    const meetingRoom = document.getElementById('meetingRoom');
    const visitorNetwork = document.getElementById('visitorNetwork');

    // Conexões
    drawLine(router, switch1);
    drawLine(router, switch2);
    drawLine(switch1, accessPoint1);
    drawLine(switch2, accessPoint2);
    drawLine(switch3, dataCenter);
    drawLine(dataCenter, server1);
    drawLine(dataCenter, server2);
    drawLine(switch1, devWorkstation1);
    drawLine(switch1, devWorkstation2);
    drawLine(switch2, designWorkstation);
    drawLine(switch1, meetingRoom);
    drawLine(switch2, visitorNetwork);
};