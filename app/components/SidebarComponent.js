class SidebarComponent extends HTMLElement {
    constructor() {
        super();
        this.attachShadow({ mode: 'open' });
        this.shadowRoot.innerHTML = `
            <style>
                #sidebar {
                    width: 60px;
                    background-color: #333;
                    display: flex;
                    flex-direction: column;
                    align-items: center;
                    padding-top: 20px;
                    transition: width 0.3s;
                }
                #sidebar.expanded {
                    width: 200px;
                }
                .icon-btn {
                    color: white;
                    font-size: 24px;
                    margin: 20px 0;
                    cursor: pointer;
                    display: flex;
                    align-items: center;
                }
                .label {
                    display: none;
                    margin-left: 10px;
                }
                #sidebar.expanded .label {
                    display: inline;
                }
            </style>
            <div id="sidebar">
                <slot></slot>
            </div>
        `;
    }

    toggleSidebar() {
        const sidebar = this.shadowRoot.querySelector("#sidebar");
        sidebar.classList.toggle("expanded");
    }

    openModal(contentId) {
        // Dispatch a custom event to open a modal based on contentId
        this.dispatchEvent(new CustomEvent("open-modal", { detail: { contentId } }));
    }
}

customElements.define('sidebar-component', SidebarComponent);