import { Runner } from './resources/dino_game/offline.js';
import {
  applyStaticI18n,
  flagForToggle,
  langToggleAria,
  onLocaleChange,
  toggleLocale,
} from './resources/dino_game/i18n.js';

const RUNNER_BASE_WIDTH = 600;
const RUNNER_BASE_HEIGHT = 150;

function syncLangButton() {
  const btn = document.querySelector('[data-lang-toggle]');
  if (!btn) {
    return;
  }
  btn.innerHTML = flagForToggle();
  btn.setAttribute('aria-label', langToggleAria());
}

function refreshPageI18n() {
  applyStaticI18n(document);
  syncLangButton();
}



function fitRunnerToStage() {
  const stage = document.querySelector('.trex-game');
  const runner = stage && stage.querySelector('.runner-container');
  if (!stage || !runner) {
    return;
  }

  const availW = stage.clientWidth;
  const availH = stage.clientHeight;
  if (availW <= 0 || availH <= 0) {
    return;
  }

  const baseW =
    parseFloat(runner.style.width) ||
    runner.offsetWidth ||
    RUNNER_BASE_WIDTH;
  const baseH =
    parseFloat(runner.style.height) ||
    runner.offsetHeight ||
    RUNNER_BASE_HEIGHT;

  const scale = Math.min(availW / baseW, availH / baseH);
  runner.style.transform = scale > 1.001 ? `scale(${scale})` : 'none';
}

window.addEventListener('load', () => {
  refreshPageI18n();

  const langBtn = document.querySelector('[data-lang-toggle]');
  if (langBtn) {
    langBtn.addEventListener('click', (e) => {
      e.preventDefault();
      toggleLocale();
    });
  }

  onLocaleChange(() => {
    refreshPageI18n();
  });

  const trexGameContainer = document.querySelector('.trex-game');
  new Runner(trexGameContainer);

  const scheduleFit = () => {
    requestAnimationFrame(fitRunnerToStage);
  };
  scheduleFit();
  window.addEventListener('resize', scheduleFit);
  if (typeof ResizeObserver !== 'undefined' && trexGameContainer) {
    const ro = new ResizeObserver(scheduleFit);
    ro.observe(trexGameContainer);
  }
});
