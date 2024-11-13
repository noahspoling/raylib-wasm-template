class SidePanelComponent extends HTMLElement {
    constructor() {
        super();
        this.attachShadow({ mode: 'open' });
        this.shadowRoot.innerHTML = `
            <style>
                #container {
                    flex: 1;
                    display: flex;
                }
                #uiSection {
                    flex: 1;
                    background: rgba(255, 255, 255, 0.2);
                    padding: 20px;
                    display: flex;
                    flex-direction: column;
                    justify-content: center;
                    align-items: center;
                    backdrop-filter: blur(10px);
                }
                #canvasContainer {
                    flex: 2;
                    display: flex;
                    flex-direction: column;
                    align-items: center;
                    justify-content: center;
                    background: radial-gradient(circle at top, #ddeeff, #aabbcc);
                }
                canvas {
                    width: 90%;
                    height: auto;
                    border-radius: 10px;
                    background-color: #ffffff;
                }
                .custom-button {
                    padding: 10px 20px;
                    margin: 5px;
                    background-color: #4CAF50;
                    color: white;
                    border: none;
                    cursor: pointer;
                }
                .custom-button:hover {
                    background-color: #45a049;
                }
            </style>
            <div id="container">
                <div id="uiSection">
                    <slot name="uiSection">``</slot>
                </div>
                <div id="canvasContainer">
                    <slot name="canvasContainer"></slot>
                </div>
            </div>
        `;
    }
}

customElements.define('container-component', ContainerComponent);