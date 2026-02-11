/**
 * PORTAFOLIO ACADÉMICO - ANIMATIONS
 * Animaciones avanzadas y efectos visuales
 */

// ========== PARTÍCULAS INTERACTIVAS ==========
class ParticleSystem {
    constructor(containerId) {
        this.container = document.getElementById(containerId) || document.querySelector('.floating-particles');
        if (!this.container) return;
        
        this.particles = [];
        this.particleCount = window.innerWidth > 768 ? 30 : 15;
        this.animationId = null;
        this.init();
        
        // Agregar listener para resize
        this.resizeHandler = () => this.handleResize();
        window.addEventListener('resize', this.resizeHandler);
    }
    
    init() {
        for (let i = 0; i < this.particleCount; i++) {
            this.createParticle();
        }
        this.animate();
    }
    
    handleResize() {
        // Recalcular límites de partículas cuando cambia el tamaño de la ventana
        const newParticleCount = window.innerWidth > 768 ? 30 : 15;
        
        // Si cambia el número de partículas, ajustar
        if (newParticleCount !== this.particleCount) {
            this.particleCount = newParticleCount;
        }
    }
    
    createParticle() {
        const particle = document.createElement('div');
        particle.className = 'particle';
        particle.style.cssText = `
            position: absolute;
            width: ${Math.random() * 4 + 2}px;
            height: ${Math.random() * 4 + 2}px;
            background: ${this.getRandomColor()};
            border-radius: 50%;
            pointer-events: none;
            opacity: ${Math.random() * 0.5 + 0.3};
            left: ${Math.random() * 100}%;
            top: ${Math.random() * 100}%;
        `;
        
        const data = {
            element: particle,
            x: Math.random() * window.innerWidth,
            y: Math.random() * window.innerHeight,
            vx: (Math.random() - 0.5) * 0.5,
            vy: (Math.random() - 0.5) * 0.5,
            size: Math.random() * 4 + 2
        };
        
        this.particles.push(data);
        this.container.appendChild(particle);
    }
    
    getRandomColor() {
        const colors = [
            'rgba(0, 212, 255, 0.8)',
            'rgba(0, 255, 136, 0.8)',
            'rgba(123, 44, 191, 0.8)',
            'rgba(255, 0, 110, 0.8)'
        ];
        return colors[Math.floor(Math.random() * colors.length)];
    }
    
    animate() {
        this.particles.forEach(p => {
            p.x += p.vx;
            p.y += p.vy;
            
            // Rebotar en los bordes (recalcular dinámicamente)
            if (p.x <= 0 || p.x >= window.innerWidth) p.vx *= -1;
            if (p.y <= 0 || p.y >= window.innerHeight) p.vy *= -1;
            
            p.element.style.transform = `translate(${p.x}px, ${p.y}px)`;
        });
        
        this.animationId = requestAnimationFrame(() => this.animate());
    }
    
    destroy() {
        if (this.animationId) {
            cancelAnimationFrame(this.animationId);
        }
        window.removeEventListener('resize', this.resizeHandler);
        this.particles.forEach(p => {
            if (p.element.parentElement) {
                p.element.remove();
            }
        });
        this.particles = [];
    }
}

// ========== EFECTO DE MOUSE TRAIL ==========
class MouseTrail {
    constructor() {
        this.trail = [];
        this.maxTrailLength = 10;
        this.timeoutIds = [];
        this.init();
    }
    
    init() {
        document.addEventListener('mousemove', (e) => {
            this.addTrailDot(e.clientX, e.clientY);
        });
    }
    
    addTrailDot(x, y) {
        // Limitar cantidad máxima de dots creados por movimiento
        if (this.trail.length >= this.maxTrailLength) {
            const oldDot = this.trail.shift();
            oldDot.remove();
            // Cancelar timeouts asociados
            const timeoutId = this.timeoutIds.shift();
            if (timeoutId) clearTimeout(timeoutId);
        }
        
        const dot = document.createElement('div');
        dot.className = 'mouse-trail-dot';
        dot.style.cssText = `
            position: fixed;
            left: ${x}px;
            top: ${y}px;
            width: 8px;
            height: 8px;
            background: var(--color-primary);
            border-radius: 50%;
            pointer-events: none;
            z-index: 9999;
            opacity: 0.6;
            transform: translate(-50%, -50%);
        `;
        
        document.body.appendChild(dot);
        this.trail.push(dot);
        
        // Animar y remover con timeouts registrados
        let timeoutId1 = setTimeout(() => {
            dot.style.transition = 'all 0.5s ease';
            dot.style.opacity = '0';
            dot.style.transform = 'translate(-50%, -50%) scale(0)';
        }, 50);
        
        let timeoutId2 = setTimeout(() => {
            if (dot.parentElement) {
                dot.remove();
            }
            const index = this.trail.indexOf(dot);
            if (index > -1) {
                this.trail.splice(index, 1);
            }
        }, 600);
        
        this.timeoutIds.push(timeoutId1, timeoutId2);
    }
    
    destroy() {
        this.timeoutIds.forEach(id => clearTimeout(id));
        this.trail.forEach(dot => {
            if (dot.parentElement) dot.remove();
        });
        this.trail = [];
        this.timeoutIds = [];
    }
}

// ========== PARALLAX SCROLL ==========
class ParallaxEffect {
    constructor() {
        this.elements = document.querySelectorAll('[data-parallax]');
        this.init();
    }
    
    init() {
        if (this.elements.length === 0) return;
        
        window.addEventListener('scroll', () => {
            this.updateParallax();
        });
        
        this.updateParallax();
    }
    
    updateParallax() {
        const scrolled = window.pageYOffset;
        
        this.elements.forEach(element => {
            const speed = element.dataset.parallax || 0.5;
            const yPos = -(scrolled * speed);
            element.style.transform = `translateY(${yPos}px)`;
        });
    }
}

// ========== TYPING EFFECT ==========
class TypingEffect {
    constructor(element, text, speed = 100) {
        this.element = element;
        this.text = text;
        this.speed = speed;
        this.index = 0;
    }
    
    start() {
        this.element.textContent = '';
        this.type();
    }
    
    type() {
        if (this.index < this.text.length) {
            this.element.textContent += this.text.charAt(this.index);
            this.index++;
            setTimeout(() => this.type(), this.speed);
        }
    }
}

// ========== CONTADOR ANIMADO ==========
function animateCounter(element, target, duration = 2000) {
    const start = 0;
    const increment = target / (duration / 16);
    let current = start;
    
    const timer = setInterval(() => {
        current += increment;
        if (current >= target) {
            element.textContent = target;
            clearInterval(timer);
        } else {
            element.textContent = Math.floor(current);
        }
    }, 16);
}

// ========== RIPPLE EFFECT ==========
function createRipple(event) {
    const button = event.currentTarget;
    const rect = button.getBoundingClientRect();
    
    const circle = document.createElement('span');
    const diameter = Math.max(rect.width, rect.height);
    const radius = diameter / 2;
    
    circle.style.cssText = `
        position: absolute;
        width: ${diameter}px;
        height: ${diameter}px;
        left: ${event.clientX - rect.left - radius}px;
        top: ${event.clientY - rect.top - radius}px;
        background: rgba(255, 255, 255, 0.3);
        border-radius: 50%;
        transform: scale(0);
        animation: ripple 0.6s ease-out;
        pointer-events: none;
    `;
    
    button.style.position = 'relative';
    button.style.overflow = 'hidden';
    button.appendChild(circle);
    
    setTimeout(() => circle.remove(), 600);
}

// ========== GLITCH EFFECT ==========
function applyGlitchEffect(element, duration = 200) {
    const originalText = element.textContent;
    const chars = '!<>-_\\/[]{}—=+*^?#________';
    let iteration = 0;
    const totalIterations = 10;
    
    const interval = setInterval(() => {
        element.textContent = originalText
            .split('')
            .map((char, index) => {
                if (index < iteration) {
                    return originalText[index];
                }
                return chars[Math.floor(Math.random() * chars.length)];
            })
            .join('');
        
        iteration += 1;
        
        if (iteration > totalIterations) {
            clearInterval(interval);
            element.textContent = originalText;
        }
    }, duration / totalIterations);
}

// ========== WAVE EFFECT ==========
function createWaveEffect(container) {
    const text = container.textContent;
    container.innerHTML = '';
    
    text.split('').forEach((char, index) => {
        const span = document.createElement('span');
        span.textContent = char;
        span.style.cssText = `
            display: inline-block;
            animation: wave 1s ease-in-out infinite;
            animation-delay: ${index * 0.1}s;
        `;
        container.appendChild(span);
    });
}

// ========== SCROLL PROGRESS BAR ==========
class ScrollProgressBar {
    constructor() {
        this.bar = this.createBar();
        this.init();
    }
    
    createBar() {
        const bar = document.createElement('div');
        bar.className = 'scroll-progress-bar';
        bar.style.cssText = `
            position: fixed;
            top: 70px;
            left: 0;
            height: 3px;
            background: var(--gradient-accent);
            width: 0%;
            z-index: 999;
            transition: width 0.1s ease;
        `;
        document.body.appendChild(bar);
        return bar;
    }
    
    init() {
        window.addEventListener('scroll', () => {
            const winScroll = document.body.scrollTop || document.documentElement.scrollTop;
            const height = document.documentElement.scrollHeight - document.documentElement.clientHeight;
            const scrolled = (winScroll / height) * 100;
            this.bar.style.width = scrolled + '%';
        });
    }
}

// ========== INICIALIZACIÓN ==========
document.addEventListener('DOMContentLoaded', () => {
    // Iniciar sistema de partículas solo en pantallas grandes
    if (window.innerWidth > 768) {
        const particles = new ParticleSystem('floatingParticles');
    }
    
    // Efecto parallax
    const parallax = new ParallaxEffect();
    
    // Barra de progreso de scroll
    const scrollBar = new ScrollProgressBar();
    
    // Agregar efecto ripple a botones y enlaces
    document.querySelectorAll('.futuristic-btn, .card-link, .nav-link').forEach(element => {
        element.addEventListener('click', createRipple);
    });
    
    // Animación de entrada para tarjetas
    const cards = document.querySelectorAll('.nav-card');
    cards.forEach((card, index) => {
        card.style.opacity = '0';
        card.style.transform = 'translateY(30px)';
        
        setTimeout(() => {
            card.style.transition = 'all 0.6s ease';
            card.style.opacity = '1';
            card.style.transform = 'translateY(0)';
        }, index * 150);
    });
    
    // Contador animado para estadísticas si existen
    document.querySelectorAll('[data-count]').forEach(element => {
        const target = parseInt(element.dataset.count);
        animateCounter(element, target);
    });
    
    console.log('✨ Animaciones inicializadas');
});

// ========== ESTILOS ADICIONALES ==========
const animationStyles = document.createElement('style');
animationStyles.textContent = `
    @keyframes ripple {
        to {
            transform: scale(4);
            opacity: 0;
        }
    }
    
    @keyframes wave {
        0%, 100% {
            transform: translateY(0);
        }
        50% {
            transform: translateY(-10px);
        }
    }
    
    .particle {
        will-change: transform;
    }
`;
document.head.appendChild(animationStyles);

// ========== EXPORTS ==========
window.TypingEffect = TypingEffect;
window.animateCounter = animateCounter;
window.createRipple = createRipple;
window.applyGlitchEffect = applyGlitchEffect;
window.createWaveEffect = createWaveEffect;