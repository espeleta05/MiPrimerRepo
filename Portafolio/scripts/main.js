/**
 * PORTAFOLIO ACADÉMICO - MAIN JAVASCRIPT
 * Funcionalidades principales y gestión de navegación
 */

// ========== VARIABLES GLOBALES ==========
let menuOpen = false;

// ========== UTILIDAD: LIMPIAR CACHE DE TAREAS ==========
/**
 * Si necesitas recargar las tareas desde JSON, ejecuta en la consola:
 * limpiarTareas() - elimina todas las tareas guardadas en localStorage
 * Esto fuerza la recarga desde los archivos JSON
 */
function limpiarTareas() {
    const keys = ['parcial1_tareas', 'parcial2_tareas', 'parcial3_tareas'];
    keys.forEach(key => {
        localStorage.removeItem(key);
        console.log(`✓ Eliminado: ${key}`);
    });
    console.log('✨ Cache limpio. Recarga la página para cargar datos frescos desde JSON');
}

// ========== INICIALIZACIÓN ==========
document.addEventListener('DOMContentLoaded', () => {
    initNavigation();
    initScrollEffects();
    initCardEffects();
    updateActiveNavLink();
    console.log('✨ Portafolio inicializado correctamente');
});

// ========== NAVEGACIÓN ==========
/**
 * Inicializa el menú de navegación y sus funcionalidades
 */
function initNavigation() {
    const menuToggle = document.getElementById('menuToggle');
    const mainNav = document.querySelector('.main-nav');
    const navLinks = document.querySelectorAll('.nav-link');
    
    // Toggle del menú móvil
    if (menuToggle) {
        menuToggle.addEventListener('click', () => {
            menuOpen = !menuOpen;
            mainNav.classList.toggle('active');
            menuToggle.classList.toggle('active');
            
            // Animación del ícono hamburguesa
            const spans = menuToggle.querySelectorAll('span');
            if (menuOpen) {
                spans[0].style.transform = 'rotate(45deg) translateY(8px)';
                spans[1].style.opacity = '0';
                spans[2].style.transform = 'rotate(-45deg) translateY(-8px)';
            } else {
                spans[0].style.transform = '';
                spans[1].style.opacity = '';
                spans[2].style.transform = '';
            }
        });
    }
    
    // Cerrar menú al hacer clic en un enlace
    navLinks.forEach(link => {
        link.addEventListener('click', () => {
            if (window.innerWidth <= 768) {
                mainNav.classList.remove('active');
                menuOpen = false;
                const spans = menuToggle.querySelectorAll('span');
                spans[0].style.transform = '';
                spans[1].style.opacity = '';
                spans[2].style.transform = '';
            }
        });
    });
    
    // Cerrar menú al hacer clic fuera
    document.addEventListener('click', (e) => {
        if (menuOpen && 
            !mainNav.contains(e.target) && 
            !menuToggle.contains(e.target)) {
            mainNav.classList.remove('active');
            menuOpen = false;
        }
    });
}

/**
 * Actualiza el enlace activo en la navegación según la página actual
 */
function updateActiveNavLink() {
    const navLinks = document.querySelectorAll('.nav-link');
    const currentPage = window.location.pathname;
    
    navLinks.forEach(link => {
        link.classList.remove('active');
        const linkPath = new URL(link.href).pathname;
        
        if (linkPath === currentPage || 
            (currentPage.includes(linkPath) && linkPath !== '/')) {
            link.classList.add('active');
        }
    });
}

// ========== EFECTOS DE SCROLL ==========
/**
 * Inicializa efectos basados en scroll
 */
function initScrollEffects() {
    // Cambiar estilo del header al hacer scroll
    const header = document.querySelector('.main-header');
    let lastScroll = 0;
    
    window.addEventListener('scroll', () => {
        const currentScroll = window.pageYOffset;
        
        // Agregar sombra al header
        if (currentScroll > 50) {
            header.style.boxShadow = '0 4px 20px rgba(0, 0, 0, 0.5)';
        } else {
            header.style.boxShadow = 'none';
        }
        
        // Ocultar/mostrar header en scroll
        if (currentScroll > lastScroll && currentScroll > 100) {
            header.style.transform = 'translateY(-100%)';
        } else {
            header.style.transform = 'translateY(0)';
        }
        
        lastScroll = currentScroll;
    });
    
    // Revelar elementos al hacer scroll
    const revealElements = document.querySelectorAll('.reveal-on-scroll');
    
    const revealObserver = new IntersectionObserver((entries) => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                entry.target.classList.add('revealed');
            }
        });
    }, {
        threshold: 0.1
    });
    
    revealElements.forEach(el => revealObserver.observe(el));
}

// ========== EFECTOS DE TARJETAS ==========
/**
 * Inicializa efectos interactivos en las tarjetas
 */
function initCardEffects() {
    const cards = document.querySelectorAll('.nav-card[data-tilt]');
    
    cards.forEach(card => {
        card.addEventListener('mousemove', handleCardTilt);
        card.addEventListener('mouseleave', resetCardTilt);
    });
}

/**
 * Efecto de inclinación 3D en tarjetas
 */
function handleCardTilt(e) {
    const card = e.currentTarget;
    const rect = card.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;
    
    const centerX = rect.width / 2;
    const centerY = rect.height / 2;
    
    const rotateX = (y - centerY) / 10;
    const rotateY = (centerX - x) / 10;
    
    card.style.transform = `
        perspective(1000px) 
        rotateX(${rotateX}deg) 
        rotateY(${rotateY}deg) 
        translateY(-8px)
        scale(1.02)
    `;
}

/**
 * Resetea la inclinación de la tarjeta
 */
function resetCardTilt(e) {
    const card = e.currentTarget;
    card.style.transform = '';
}

// ========== GESTIÓN DE TAREAS ==========
/**
 * Sistema simple para gestionar tareas (simulado, sin backend)
 * En una implementación real, esto se conectaría a una base de datos
 */
const TaskManager = {
    // Almacenamiento local de tareas
    tasks: JSON.parse(localStorage.getItem('portfolioTasks')) || {
        parcial1: [],
        parcial2: [],
        parcial3: [],
        proyecto: []
    },
    
    /**
     * Guarda las tareas en localStorage
     */
    save() {
        localStorage.setItem('portfolioTasks', JSON.stringify(this.tasks));
    },
    
    /**
     * Agrega una nueva tarea
     */
    addTask(parcial, taskData) {
        const task = {
            id: Date.now(),
            title: taskData.title,
            description: taskData.description,
            date: new Date().toISOString(),
            status: 'in-progress',
            ...taskData
        };
        
        this.tasks[parcial].push(task);
        this.save();
        return task;
    },
    
    /**
     * Obtiene todas las tareas de un parcial
     */
    getTasks(parcial) {
        return this.tasks[parcial] || [];
    },
    
    /**
     * Actualiza una tarea existente
     */
    updateTask(parcial, taskId, updates) {
        const taskIndex = this.tasks[parcial].findIndex(t => t.id === taskId);
        if (taskIndex !== -1) {
            this.tasks[parcial][taskIndex] = {
                ...this.tasks[parcial][taskIndex],
                ...updates
            };
            this.save();
            return true;
        }
        return false;
    },
    
    /**
     * Elimina una tarea
     */
    deleteTask(parcial, taskId) {
        this.tasks[parcial] = this.tasks[parcial].filter(t => t.id !== taskId);
        this.save();
    },
    
    /**
     * Obtiene el conteo de tareas por parcial
     */
    getTaskCount(parcial) {
        return this.tasks[parcial]?.length || 0;
    }
};

// ========== UTILIDADES ==========
/**
 * Formatea una fecha a formato legible
 */
function formatDate(dateString) {
    const options = { 
        year: 'numeric', 
        month: 'long', 
        day: 'numeric',
        hour: '2-digit',
        minute: '2-digit'
    };
    return new Date(dateString).toLocaleDateString('es-MX', options);
}

/**
 * Genera un ID único
 */
function generateId() {
    return `task_${Date.now()}_${Math.random().toString(36).substr(2, 9)}`;
}

/**
 * Muestra una notificación temporal
 */
function showNotification(message, type = 'info') {
    const notification = document.createElement('div');
    notification.className = `notification notification-${type}`;
    notification.textContent = message;
    notification.style.cssText = `
        position: fixed;
        top: 100px;
        right: 20px;
        padding: 1rem 1.5rem;
        background: ${type === 'success' ? 'rgba(0, 255, 136, 0.9)' : 'rgba(0, 212, 255, 0.9)'};
        color: var(--color-bg-darker);
        border-radius: var(--border-radius-md);
        font-weight: 600;
        z-index: 10000;
        animation: slideIn 0.3s ease;
        box-shadow: var(--shadow-lg);
    `;
    
    document.body.appendChild(notification);
    
    setTimeout(() => {
        notification.style.animation = 'slideOut 0.3s ease';
        setTimeout(() => notification.remove(), 300);
    }, 3000);
}

/**
 * Anima la entrada de elementos
 */
function animateElements(selector, delay = 100) {
    const elements = document.querySelectorAll(selector);
    elements.forEach((el, index) => {
        setTimeout(() => {
            el.style.opacity = '0';
            el.style.transform = 'translateY(20px)';
            el.style.transition = 'all 0.5s ease';
            
            setTimeout(() => {
                el.style.opacity = '1';
                el.style.transform = 'translateY(0)';
            }, 50);
        }, index * delay);
    });
}

/**
 * Navega suavemente a una sección
 */
function smoothScrollTo(elementId) {
    const element = document.getElementById(elementId);
    if (element) {
        element.scrollIntoView({
            behavior: 'smooth',
            block: 'start'
        });
    }
}

/**
 * Copia texto al portapapeles
 */
async function copyToClipboard(text) {
    try {
        await navigator.clipboard.writeText(text);
        showNotification('¡Copiado al portapapeles!', 'success');
        return true;
    } catch (err) {
        console.error('Error al copiar:', err);
        showNotification('Error al copiar', 'error');
        return false;
    }
}

// ========== EXPORTS (para uso en otros archivos) ==========
window.TaskManager = TaskManager;
window.formatDate = formatDate;
window.generateId = generateId;
window.showNotification = showNotification;
window.animateElements = animateElements;
window.smoothScrollTo = smoothScrollTo;
window.copyToClipboard = copyToClipboard;

// ========== ESTILOS ADICIONALES PARA NOTIFICACIONES ==========
const style = document.createElement('style');
style.textContent = `
    @keyframes slideIn {
        from {
            transform: translateX(400px);
            opacity: 0;
        }
        to {
            transform: translateX(0);
            opacity: 1;
        }
    }
    
    @keyframes slideOut {
        from {
            transform: translateX(0);
            opacity: 1;
        }
        to {
            transform: translateX(400px);
            opacity: 0;
        }
    }
`;
document.head.appendChild(style);

console.log('🚀 Sistema de tareas cargado:', TaskManager);